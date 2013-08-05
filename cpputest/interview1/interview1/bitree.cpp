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

void DestoryBiTree(BiTree T) // PostOrder
{
    if (T)
    {
        DestoryBiTree(T->lchild);
        DestoryBiTree(T->rchild);
        delete T;
    }
}

static char buffer[1024];
static int charnum = 0;
void Print(BiTNode * elem)
{
    assert(elem != NULL);
    
    buffer[charnum++] = elem->data;
    buffer[charnum] = '\0';
}

void PreOrderTraverse(BiTree T, void (Visit)(BiTNode *))
{
    if (T){
        Visit(T);
        PreOrderTraverse(T->lchild, Visit);
        PreOrderTraverse(T->rchild, Visit);
    }
}

TEST(BiTree, CreateBiTree)
{
    BiTree T = NULL;
    char p[] = "ab  cd   ";
    int n = 0;
    CreateBiTree((T), p, n);
    
    charnum = 0;
    PreOrderTraverse(T, Print);
    DestoryBiTree(T);
    
    STRCMP_EQUAL("abcd", buffer);
}

TEST(BiTree, CreateBiTree2)
{
    BiTree T = NULL;
    char p[] = "ab  c d  ";
    int n = 0;
    CreateBiTree((T), p, n);
    
    charnum = 0;
    PreOrderTraverse(T, Print);
    DestoryBiTree(T);
    
    STRCMP_EQUAL("abcd", buffer);
}

