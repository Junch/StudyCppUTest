#!/usr/bin/python

############# Problem 1: Multiples of 3 and 5
#
# If we list all the natural numbers below 10 that are multiples
# of 3 or 5, we get 3, 5, 6 and 9. The sum ofthese multiples is 23.
# Find the sum of all the multiples of 3 or 5 below 1000.
#

def multiples(n):
    arr = []
    for i in range(1, n):
        if i % 3 == 0 or i % 5 == 0 :
            arr.append(i)
    
    return arr

def sum(arr):
    total = 0
    for i in arr:
        total = total + i
    return total

print ("Problem1: Multiples of 3 and 5")
print ('-'*30)

num=1000
arr = multiples(num)
total = sum(arr)
print ("num=%d, total=%d" % (num, total))