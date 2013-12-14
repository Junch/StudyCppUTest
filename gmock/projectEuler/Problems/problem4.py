#!/usr/bin/python

############# Problem 4: Largest palindrome product
#
# http://projecteuler.net/problem=4
# A palindromic number reads the same both ways. The largest
# palindrome made from the product of two 2-digit numbers is
# 9009 = 91 * 99.
#
# Find the largest palindrome made from the product of two
# 3-digit numbers.

def isPalindrome(n):
    digits=[]

    while True:
        a = n % 10
        digits.append(a)
        # To support python 3, it is updated
        # This code could also run in python 2.7
        # http://blog.csdn.net/fhd001/article/details/6969864
        b = n // 10
        if (b == 0):
            break
        n = b

    i = 0
    j = len(digits) - 1
    while(i<j):
        if(digits[i] == digits[j]):
            i = i+1
            j = j-1
        else:
            return False
    return True   

def getNumber(a, b):
    ret = []
    number = 0
    for i in range(a, b):
        for j in range(i, b):
            k = i * j
            if k > number and isPalindrome(k):
                number = k
                ret = [number, i, j]
    return ret

print ("Problem 4: Largest palindrome product")
print ('-'*30)
print getNumber(101, 1000)
