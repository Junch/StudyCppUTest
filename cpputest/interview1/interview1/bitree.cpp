#include <CppUTest/TestHarness.h>
#include <cassert>

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

int DepthBiTree(BiTree T)
{
    if (!T)
        return 0;
    
    int ld = DepthBiTree(T->lchild);
    int rd = DepthBiTree(T->rchild);
    
    int length = (ld > rd)? ld + 1: rd + 1;
    return length;
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

//////////////////////////////////////////
// TEST
//////////////////////////////////////////

TEST_GROUP(BiTree)
{
    BiTree T = NULL;
    
    void teardown(){
        DestoryBiTree(T);
    }
};

TEST(BiTree, CreateBiTree)
{
    char p[] = "ab  cd   ";
    int n = 0;
    CreateBiTree((T), p, n);
    
    charnum = 0;
    PreOrderTraverse(T, Print);
    
    STRCMP_EQUAL("abcd", buffer);
}

TEST(BiTree, CreateBiTree2)
{
    char p[] = "ab  c d  ";
    int n = 0;
    CreateBiTree((T), p, n);
    
    charnum = 0;
    PreOrderTraverse(T, Print);
    
    STRCMP_EQUAL("abcd", buffer);
}

TEST(BiTree, DepthBiTree)
{
    char p[] = "abd   ce g  f  ";
    int n = 0;
    CreateBiTree((T), p, n);
    
    charnum = 0;
    PreOrderTraverse(T, Print);
    STRCMP_EQUAL("abdcegf", buffer);
    
    int depth = DepthBiTree(T);
    LONGS_EQUAL(4, depth);
}

