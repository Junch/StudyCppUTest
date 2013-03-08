#!/usr/bin/python

############# Problem 2: Even Fibonacci numbers
#
# Each new term in the Fibonacci sequence is generated by adding the
# previous two terms. By starting with 1 and 2, the first 10 terms will be:
#   1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...
# By considering the terms in the Fibonacci sequence whose values do not
# exceed four million, find the sum of the even-valued terms.
#

def fibonacci(n):
    if (n==1 or n==2):
        return n;
    return fibonacci(n-1) + fibonacci(n-2)

def sum(limit):
    total = 0
    i = 1
    term = 1
    while (term < limit):
        if (term % 2 == 0):
            total = total + term
        i = i + 1
        term = fibonacci(i)
    return total

print ("Problem 2: Even Fibonacci numbers")
print ('-'*30)

limit=4000000
total = sum(limit)
print ("limit=%d, total=%d" % (limit, total))
