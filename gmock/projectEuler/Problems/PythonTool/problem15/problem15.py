#!/usr/bin/python
import time

class LatticePaths(object):
    dict = {}
    def calculate(self, w, h):
        if(w==0 or h==0):
            return 1

        if (w,h) in self.dict:
            return self.dict[(w,h)]
        elif (h,w) in self.dict:
            return self.dict[(h,w)]

        value = self.calculate(w, h-1) + self.calculate(w-1,h)
        self.dict[(w,h)] = value
        return value

def main():
    lp = LatticePaths()
    number = lp.calculate(20, 20)
    print(number)

if __name__ == "__main__":
    starttime = time.clock()
    main()
    endtime = time.clock()
    print("It takes %f:" % (endtime-starttime))
