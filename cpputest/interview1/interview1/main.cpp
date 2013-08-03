#include <CppUTest/CommandLineTestRunner.h>
#include <cassert>

TEST_GROUP(TestGroup1)
{
};

void inverseCopy(char* src, char* dest)
{
    assert(src != NULL && dest != NULL);
    
    int len = strlen(src);
    int i = len - 1;
    int k = 0;
    
    while(i >= 0){
        while(src[i] == ' ' && i >= 0 ){
            dest[k] = ' ';
            --i;
            ++k;
        }
        
        int j = i;
        while(src[j] != ' ' && j >= 0)
            --j;
            
        memcpy(dest+k, src+j+1, i-j);
        k += i-j;
        i = j;
    }
    
    *(dest+len) = '\0';
}

TEST(TestGroup1, inverseCopy1)
{
    char * s1 = "hello world";
    char * s2 = "world hello";
       
    char *s = new char[strlen(s1) + 1];
    inverseCopy(s1, s);
    
    STRCMP_EQUAL(s2, s);
    delete[] s;
}

TEST(TestGroup1, inverseCopy2)
{
    char* s1 ="hello  world ";
    char* s2 =" world  hello";
    char* s = new char[strlen(s1) + 1];
    inverseCopy(s1, s);
    
    STRCMP_EQUAL(s2, s);
    delete[] s;
}

TEST(TestGroup1, inverseCopy3)
{
    char* s1 ="  hello  world";
    char* s2 ="world  hello  ";
    char* s = new char[strlen(s1) + 1];
    inverseCopy(s1, s);
    
    STRCMP_EQUAL(s2, s);
    delete[] s;
}

int main(int argc, const char * argv[])
{
    return CommandLineTestRunner::RunAllTests(argc, argv);
}
