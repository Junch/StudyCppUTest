#!/usr/bin/python

############# Problem 3: Largest prime factor
#
# http://projecteuler.net/problem=3
# The prime factors of 13195 are 5, 7, 13 and 29.
# What is the largest prime factor of the number 600851475143 ?
#

#####################################
# The function below is very stupid
#####################################
"""
def divide(n, c):
    global x
    x = n
    for i in range(c, n):
        if (i * i > n):
            break
        if (n % i == 0):
            a = i
            b = n / i
            return divide(b, a)
"""

def divide(n):
    i = 2
    while(i < n):
        if (i * i > n):
            break
        if (n % i == 0):
            n = n/i
        else:
            i = i + 1
    return n

print ("Problem 3: Largest prime factor")
print ('-'*30)

number = 600851475143
factor = divide(number)
print "Number=%d, Largest prime factor=%d" % (number, factor)
