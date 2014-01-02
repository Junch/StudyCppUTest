//
//  shared_ptr.cpp
//  Cpp11
//
//  Created by Jun on 14-1-2.
//  Copyright (c) 2014年 Jun. All rights reserved.
//

#include <gtest/gtest.h>
#include <memory>
using namespace testing;
using namespace std;

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
    class Foo {
    public:
        Foo() {
            printf("Foo::Foo() %d\n", __LINE__);
        }
        
        ~Foo() {
            printf("Foo::~Foo() %d\n", __LINE__);
        }
    };
    
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

TEST(shared_ptr, allocAndDeleter)
{
    class Foo{
        
    };
    
    class FooHandler
    {
    public:
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
    
    class Functor
    {
    public:
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

TEST(shared_ptr, itemInContainer)
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

TEST(shared_ptr, itemInContainer2)
{
    class Foo {
    public:
        ~Foo() {
            printf("Foo::~Foo() %d\n", __LINE__);
        }
    };
    
    vector<shared_ptr<Foo> > v;
    v.push_back(make_shared<Foo>());
    v.push_back(make_shared<Foo>());
}
