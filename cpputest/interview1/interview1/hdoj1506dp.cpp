//
//  hdoj1506.cpp
//  interview1
//  http://acm.hdu.edu.cn/showproblem.php?pid=1506
//  Created by wolf76 on 13-8-24.
//  Copyright (c) 2013年 com.wolf76. All rights reserved.
//

//#include <cstdio>
//#include <cstring>
//#define maxn 100010
//int l[maxn],r[maxn],n,i;
//int main()
//{
//	__int64 a[maxn],max,area;
//	while(scanf("%d",&n)&&n!=0){
//		for(i=1;i<=n;i++){
//			scanf("%I64d",&a[i]);
//			l[i]=r[i]=i;//l[i]表示左边边界，r[i]表示右边边界
//		}
//		a[0]=a[n+1]=-1;
//		for(i=1;i<=n;i++)
//			while(a[l[i]-1]>=a[i])
//				l[i]=l[l[i]-1];
//		for(i=n;i>=1;i--)
//			while(a[r[i]+1]>=a[i])
//				r[i]=r[r[i]+1];
//		for(i=1,max=0;i<=n;i++){
//			area=(r[i]-l[i]+1)*a[i];
//			max=area>max?area:max;
//		}
//		printf("%I64d\n",max);
//	}
//	return 0;
//}

#include <CppUTest/TestHarness.h>
#include <stdio.h>
#ifdef ONLINE_JUDGE
typedef unsigned __int64 uint64_t;
#else
#include <stdint.h>
#endif

// It is clear now. The HDOJ runs on the WIN32 platform. Even the G++ is still run on the WIN32 platform
// The uint64_t defined in the stdint.h could not work well on the HDOJ.

namespace HDOJ1506DP {
    
#define MAX 100010
int height[MAX], lleft[MAX], lright[MAX]; // There is a std::left function
int N;

uint64_t largestRect()
{
    for (int i=1;i<=N; ++i){
        int j=i;
        while (j>1 && height[j-1]>=height[i])
            j=lleft[j-1];
        
        lleft[i]=j;
    }
    
    for (int i=N;i>0; --i){
        int j=i;
        while (j<N && height[j+1]>=height[i])
            j=lright[j+1];
        
        lright[i]=j;
    }
 
    uint64_t max=0;
    for(int i=1; i<=N; ++i) {
        uint64_t a = ((uint64_t)height[i]) * (lright[i] - lleft[i] + 1);
        if (max < a)
            max = a;
    }

    return max;
}

int main()
{
    int n;
    while (scanf("%d",&n) && n) {
        for (int i=1; i<=n; ++i) {
            scanf("%d", height+i);
        }
        N = n;
#ifdef ONLINE_JUDGE
        printf("%I64u\n", largestRect());
#else
        printf("%llu\n", largestRect());
#endif
    }
    
    return 0;
}
    
TEST_GROUP(HDOJ1506DP){
    
};

IGNORE_TEST(HDOJ1506DP, main){
    FILE *fin = freopen("./data/hdoj1506.txt", "r", stdin);
    if (fin == NULL) {
        FAIL("Filed to open the test file hdoj1506.txt");
        return;
    }
    main();
    fclose(fin);
}

TEST(HDOJ1506DP, case1){
    N=3;
    height[1]=2;
    height[2]=1;
    height[3]=2;
    
    uint64_t m = largestRect();
    LONGS_EQUAL(3, m);
}

TEST(HDOJ1506DP, case2){
    N=7;
    height[1]=2;
    height[2]=1;
    height[3]=4;
    height[4]=5;
    height[5]=1;
    height[6]=3;
    height[7]=3;
    
    uint64_t m = largestRect();
    LONGS_EQUAL(8, m);
}
    
TEST(HDOJ1506DP, case3){
    N=6;
    height[1]=2;
    height[2]=5;
    height[3]=2;
    height[4]=5;
    height[5]=5;
    height[6]=2;
    
    uint64_t m = largestRect();
    LONGS_EQUAL(12, m);
}
    
    
}//namespace
