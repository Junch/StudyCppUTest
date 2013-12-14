#!/usr/bin/python

############# Problem 5: Smallest multiple
#
# http://projecteuler.net/problem=5
# 2520 is the smallest number that can be divided by each of the
# numbers from 1 to 10 without any remainder.
# What is the smallest positive number that is evenly divisible by
# all of the numbers from 1 to 20?
#

def biggestFactor(a, b):
    c = a % b
    while (c != 0):
        a = b
        b = c
        c = a % b
    return b
    
def smallestMultiple2(a, b):
    c = biggestFactor(a, b)
    return (a*b)/c

def smallestMultiple(n):
    number = 2
    for i in range(2, n+1):
        number = smallestMultiple2(i, number)
    return number

print smallestMultiple(10)
print smallestMultiple(20)
    