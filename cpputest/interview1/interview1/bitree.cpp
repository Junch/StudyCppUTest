#include <CppUTest/CommandLineTestRunner.h>
#include <cassert>

TEST_GROUP(BiTree)
{
};

typedef struct BiTNode {
    char data;
    struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

BiTree CreateBiTree(BiTree& T, char* sz, int& n)
{
    assert(n < strlen(sz));
    char ch = sz[n];
    if (ch == ' ')
    {
        T=NULL;
        ++n;
    }
    else {
        T = new BiTNode;
        T->data = ch;
        ++n;
        CreateBiTree(T->lchild, sz, n);
        CreateBiTree(T->rchild, sz, n);
    }
    return T;
}

