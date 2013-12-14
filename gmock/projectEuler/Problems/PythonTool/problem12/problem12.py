#!/usr/bin/python

import unittest

def triangular(n):
    return n*(n+1)//2

def divisors(n):
    k = 2
    total = 2 # [1,n] is default the divisor
    kk = n**0.5+1
    while k < kk:
        if(n % k == 0):
            total += 2
        k += 1
    return total

class problem12test (unittest.TestCase):
    def test_problem12(self):
        self.assertEqual(2, divisors(triangular(2)))
        self.assertEqual(4, divisors(triangular(6)))
        self.assertEqual(6, divisors(triangular(7)))

if __name__ == "__main__":
    #unittest.main()
    n = 100
    while (divisors(triangular(n)) < 500):
        n += 1
    print (n)
    print(triangular(n))
