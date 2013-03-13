#!/usr/bin/python
import unittest
import sys

def collatz(n):
    len = 1
    while (n > 1):
        if (n%2 == 0):
            n=n//2
        else:
            n=3*n+1
        len += 1
    return len

def main():
    i = 1
    maxlen = 0
    maxi = 0

    largesti = int(sys.argv[1])
    while(i<largesti):
        len = collatz(i)
        if(maxlen < len):
            maxlen = len
            maxi = i
        i += 1
    print("maxlen=%d "% maxlen)
    print("starting number=%d " % maxi)

class problem14(unittest.TestCase):
    def test_problem14(self):
        self.assertEqual(10, collatz(13))

if __name__ == "__main__":
    #unittest.main()
    main()