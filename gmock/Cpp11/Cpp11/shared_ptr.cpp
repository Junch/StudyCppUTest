//
//  shared_ptr.cpp
//  Cpp11
//
//  Created by Jun on 14-1-2.
//  Copyright (c) 2014年 Jun. All rights reserved.
//  http://en.cppreference.com/w/cpp/memory/shared_ptr
//  http://www.gps.caltech.edu/~walter/arx/ArX-2.2.4/src/boost/libs/smart_ptr/sp_techniques.html

#include <gtest/gtest.h>
#include <memory>
using namespace testing;
using namespace std;

class Foo {
public:
    Foo() {
        printf("Foo::Foo()\n");
    }
    
    virtual ~Foo() {
        printf("Foo::~Foo()\n");
    }
};

class Goo: public Foo {
public:
    Goo() {
        printf("Goo::Goo()\n");
    }
    
    ~Goo() {
        printf("Goo::~Goo()\n");
    }
};

TEST(shared_ptr, use_count)
{
    shared_ptr<int> p;
    ASSERT_EQ(0, p.use_count());
    
    {
        shared_ptr<int> q = make_shared<int>(5);
        ASSERT_EQ(1, q.use_count());
        
        p = q;
        ASSERT_EQ(2, p.use_count());
        ASSERT_EQ(2, q.use_count());
    }
    
    ASSERT_EQ(1, p.use_count());
}

TEST(shared_ptr, use_count2)
{
    class A{
    public:
        A()=default;
        A(shared_ptr<Foo> f):_f(f){ }
        
        shared_ptr<Foo> _f;
    };
    
    shared_ptr<Foo> foo = make_shared<Foo>();
    A a(foo);
    A b = a;
    
    ASSERT_EQ(a._f.get(), b._f.get());
    A c;
    c = a;
    ASSERT_EQ(a._f.get(), c._f.get());
    
    ASSERT_EQ(4, a._f.use_count());
}

TEST(shared_ptr, reset)
{
    shared_ptr<int> p=make_shared<int>(5);
    shared_ptr<int> q=p;
    shared_ptr<int> r=p;
    ASSERT_EQ(3, p.use_count());
    ASSERT_EQ(3, q.use_count());
    ASSERT_EQ(3, r.use_count());
    
    p.reset();
    ASSERT_EQ(0, p.use_count());
    ASSERT_EQ(2, q.use_count());
    ASSERT_EQ(2, r.use_count());
    
    q.reset();
    ASSERT_EQ(0, q.use_count());
    ASSERT_EQ(1, r.use_count());
}

TEST(shared_ptr, allocAndDeleter)
{
    struct FooHandler
    {
        static Foo* alloc()
        {
            Foo* f = new Foo;
            std::cout << " a new foo was created" <<std::endl;
            return f;
        }
        static void free(Foo* f)
        {
            delete f;
            std::cout << " foo destroyed" <<std::endl;
        }
    };
    
    struct Functor
    {
        void operator()(Foo* f){
            delete f;
            std::cout << " foo destroyed in Functor" <<std::endl;
        }
    };
    
    shared_ptr<Foo> foo(FooHandler::alloc(), &FooHandler::free);
    shared_ptr<Foo> goo(new Foo, &FooHandler::free);
    shared_ptr<Foo> hoo(new Foo, Functor());
}

TEST(shared_ptr, makeUseOfDelecter)
{
    class Handler {
    public:
        static void free(void *) {
            printf(" free is called\n");
        }
        
        static void freeInt(int *) {
            printf(" freeInt is called\n");
        }
    };
    
    shared_ptr<void> f(nullptr, &Handler::free);
    shared_ptr<void> g(nullptr, &Handler::freeInt);
}

TEST(shared_ptr, pointsToContainer)
{
    shared_ptr<vector<int> > spv = make_shared<vector<int> > (10, 2);
    ASSERT_EQ(10, spv->size());
    for (auto i: *spv)
        ASSERT_EQ(2, i);
}

TEST(shared_ptr, pointsToArray)
{
    shared_ptr<Foo> foo(new Foo[2], std::default_delete<Foo[]>());
    {
        printf("******\n");
        shared_ptr<Foo> goo(new Goo);
        foo = goo;
        printf("******\n");
    }
}

TEST(shared_ptr, isItemInContainer)
{
    typedef vector<shared_ptr<int> > vs;
    vs v(5);
    int i=0;
    for (auto& item: v)
        item = make_shared<int>(++i);
    
    i=0;
    for (auto item: v)
        ASSERT_EQ(++i, *item);
}

TEST(shared_ptr, isItemInContainer2)
{
    vector<shared_ptr<Foo> > v;
    v.push_back(make_shared<Foo>());
    v.push_back(make_shared<Foo>());
}

TEST(shared_ptr, preventDeleteRawPointer)
{
    class X
    {
    private:
        ~X() = default;
        
        class deleter;
        friend class deleter;
        
        class deleter
        {
        public:
            
            void operator()(X * p) { delete p; }
        };
        
    public:
        
        static shared_ptr<X> create()
        {
            shared_ptr<X> px(new X, X::deleter());
            return px;
        }
    };
    
    shared_ptr<X> x= X::create();
}

TEST(shared_ptr, weak_ptr)
{
    // std::weak_ptr 用来表达临时所有权的概念：当某个对象只有存在时才需要被访问，
    // 而且随时可能被他人删除时，可以使用 std::weak_ptr 来跟踪该对象。需要获得
    // 临时所有权时，则将其转换为 std::shared_ptr，此时如果原来的 std::shared_ptr
    // 被销毁，则该对象的生命期将被延长至这个临时的 std::shared_ptr 同样被销毁为止。
    // 此外，std::weak_ptr 还可以用来避免 std::shared_ptr 的循环引用。
    
    std::weak_ptr<int> w;
    
    auto func = [&](){
        if (auto spt = w.lock()) { // Has to be copied into a shared_ptr before usage
            std::cout << *spt << "\n";
        }
        else {
            std::cout << "w is expired\n";
        }
    };
    
    {
        auto sp = make_shared<int>(49);
        w = sp;
        func();
    }
    
    func();
}

TEST(shared_ptr, enable_shared_from_this)
{
    // 使用情景：当类对象被 shared_ptr 管理时，需要在类自己定义的函数里把当前类对象作为参数
    // 传给其他函数时，这时需要传递一个 shared_ptr ，否则就不能保持 shared_ptr 管理这个类
    // 对象的语义（因为有一个 raw pointer 指向这个类对象，而 shared_ptr 对类对象的这个引
    // 用没有计数，很有可能 shared_ptr 已经把类对象资源释放了，而那个调用函数还在使用类对象
    
    // The key point is that the "obvious" technique of just returning shared_ptr<Y>(this)
    // is broken, because this winds up creating multiple distinct shared_ptr objects with
    // separate reference counts. For this reason you must never create more than one
    // shared_ptr from the same raw pointer.
    
    struct Good: enable_shared_from_this<Good>
    {
        shared_ptr<Good> getptr() {
            return shared_from_this();
        }
    };
    
    struct Bad
    {
        shared_ptr<Bad> getptr() {
            return shared_ptr<Bad>(this);
        }
        ~Bad() { std::cout << "Bad::~Bad() called\n"; }
    };
    
    // Good: the two shared_ptr's share the same object
    std::shared_ptr<Good> p1(new Good);
    std::shared_ptr<Good> p2 = p1->getptr();
    std::cout << "p2.use_count() = " << p2.use_count() << '\n';
    
    auto func = [](Good * g){
        shared_ptr<Good> p3 = g->getptr();
        std::cout << "p3.use_count() = " << p3.use_count() << '\n';
    };
    
    func(p1.get());

    // Bad, each shared_ptr thinks it's the only owner of the object
    // std::shared_ptr<Bad> bp1(new Bad);
    // std::shared_ptr<Bad> bp2 = bp1->getptr();
    // std::cout << "bp2.use_count() = " << bp2.use_count() << '\n';
}
