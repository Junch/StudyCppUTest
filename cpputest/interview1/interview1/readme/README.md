算法
===

###JDOJ1348: 数组中的逆序对
问题的要点是将时间复杂度控制在$nlogn$，而不是$n^2$。解题思路参考归并排序。  
另外两组排好序的数组如何来计算逆序对？  
$a_0,a_1,…,a_n$   
$b_0,b_1,…,b_m$   
假设$a_i>b_j$，那么$a_i$及$a_i$以后的元素都与$b_j$形成逆序对，逆序对的个数为$n-i+1$。

```{.cpp .numberLines}
    void merge(int a[], int low, int high, int t[])
    {
        int mid = (low + high)/2;
        int i=low;
        int j=mid;
        int k=low;
        while (i < mid && j< high) {
            if (a[i] <= a[j])
                t[k++] = a[i++];
            else {
                t[k++] = a[j++];
                //a[j]与{a[i],...,a[mid-1]}的所有元素都构成逆序数
                reverseOrder += mid-i;
            }
        }
        
        while (i<mid)
            t[k++] = a[i++];
        
        while (j<high)
            t[k++] = a[j++];
        
        for (i=low; i<high; i++)
            a[i] = t[i];
    }
    
    void mergesort(int a[], int low, int high, int t[])
    {
        if (high - low > 1) // If the array contains two more elements
        {
            int mid = (low + high)/2;
            mergesort(a, low, mid, t);
            mergesort(a, mid, high, t);
            merge(a, low, high, t);
        }
    }
```

###JDOJ1369: 字符串的排列
棘手的是处理重复的字符。基本思路是**保持重复字符的原有顺序**。比如AAB，将重复的字符A不妨分别标记为$A_0$, $A_1$，这个字符串标记为$A_0A_1$B。排列中可以出现$A_0$B$A_1$，但不可以出现$A_1$B$A_0$。如果$A_0$没有出现，那么$A_1$也不应该出现，这样避免输出重复的排列。

```{.cpp .numberLines}
    void permutation(char s[], char t[], bool used[], int len, int index)
    {
        if (len == index) {
            printf("%s\n", t);

            return;
        }
        
        for (int i=0; i<len; i++) {
            if (used[i])
                continue;
            
            if (i>0 && s[i]==s[i-1] && !used[i-1])
                continue;
            
            t[index] = s[i];
            ++index;
            used[i] = true;
            permutation(s, t, used, len, index);
            used[i] = false;
            --index;
        }
    }

```

###HDOJ1003: Max Sum

$b_i$表示以$a_i$元素结尾的最大子段和，则所求的最大子段为$max\{b_i\}, 0 \leq i < n$。

``` {.cpp .numberLines}
b[0]=a[0];
for (int i=1; i<len; i++)
    if (b[i-1] < 0)
        b[i] = a[i];
    else
        b[i] = b[i-1] + a[i];

```
