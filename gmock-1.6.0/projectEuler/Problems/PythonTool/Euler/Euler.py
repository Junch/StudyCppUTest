import math

def problem_13():
    data = []
    def getData():
        fp = open("problem13.txt", "r")
        for line in fp:
            line = line.rstrip()
            data.append(int(line))
    getData()
    s = str(sum(data))
    for i in range(10):
        print (s[i], end='') 

def problem_15():
    def pascal_row(n):
        r = [1]
        for i in range(1, n+1):
            r1 = [1 for j in range(i + 1)]
            for j in range(1, i):
                r1[j] = r[j] + r[j-1]
            r = r1[:]
        
        return r

    def lattice(n):
        p = 0
        for i in pascal_row(n):
            p += i*i
            
        return p

    print(lattice(20))

def problem_16():
    print(sum([int(x) for x in (str(2**1000))]))

def problem_17():
    dict = {}
    dict[1] = 'one'
    dict[2] = 'two'
    dict[3] = 'three'
    dict[4] = 'four'
    dict[5] = 'five'
    dict[6] = 'six'
    dict[7] = 'seven'
    dict[8] = 'eight'
    dict[9] = 'nine'
    dict[10] = 'ten'
    dict[11] = 'eleven'
    dict[12] = 'twelve'
    dict[13] = 'thirteen'
    dict[14] = 'fourteen'
    dict[15] = 'fifteen'
    dict[16] = 'sixteen'
    dict[17] = 'seventeen'
    dict[18] = 'eighteen'
    dict[19] = 'nineteen'
    dict[20] = 'twenty'
    dict[30] = 'thirty'
    dict[40] = 'forty'
    dict[50] = 'fifty'
    dict[60] = 'sixty'
    dict[70] = 'seventy'
    dict[80] = 'eighty'
    dict[90] = 'ninety'
    dict[1000] = 'onethousand'

    def calc2bits(s):
        total = 0
        num = 10*s[0] + s[1]
        if num in dict:
            total += len(dict[num])
        else:
            total += len(dict[s[0]*10]) + len(dict[s[1]])
        return total

    def calcNumber(num):
        s = [int(x) for x in str(num)]
        unit = len(s)
        wordlen = 0

        if (unit == 1):
            wordlen += len(dict[s[0]])
        elif (unit == 2):
            wordlen += calc2bits(s)
        elif (unit == 3):
            wordlen += len(dict[s[0]]) + len('hundred')
            if (s[1] == 0 and s[2] == 0):
                pass
            else:
                wordlen += len('and') 
                ss = [s[1],s[2]]
                wordlen += calc2bits(ss)
        return wordlen

    total = 0
    for i in range(1,1000):
        total += calcNumber(i)
    total += len(dict[1000])
    print (total)

def problem_18():
    data = []
    dict = {}
    def getData():
        fp = open("problem18.txt", "r")
        for line in fp:
            line = line.rstrip()
            a = [int(x) for x in line.split()]
            data.append(a)

    getData()
    m = len(data[-1])
    for i in range(m):
        for j in range(i+1):
            left = 0
            right = 0
            if (j>0):
                left = dict[(i-1,j-1)]
            if (j<i):
                right = dict[(i-1,j)]
            parent = max(left, right)
            dict[(i,j)] = parent + data[i][j]
    maxvalue = max(dict.values())
    print(maxvalue)

def problem_19():
    dict={1:31, 2:28, 3:31, 4:30, 5:31,6:30, \
          7:31, 8:31, 9:30,10:31,11:30,12:31}

    def isLeapYear(year):
        if (year % 400 == 0):
            return True
        if (year % 100 == 0):
            return False
        if (year % 4 == 0):
            return True
        return False 

    def daysPerYear(year):
        days = 365
        if isLeapYear(year):
            days = 366
        return days

    def daysFrom1900(year, month):
        days = 1
        for i in range(1, month):
            days += dict[i]
        if (month >= 3 and isLeapYear(year)):
            days += 1

        for i in range(1900, year):
            days += daysPerYear(i)
        return days

    sundays=0
    for i in range(1901, 2001): # I used 2000 first!
        for j in range(1, 13): # I used 12 first!
            days = daysFrom1900(i,j)
            if (days % 7 == 0):
                sundays += 1
                print("(%d,%d)"%(i,j))
    print (sundays)

def problem_22():
    data=[]
    def getData():
        buff=[]
        fp = open("problem22.txt","r")
        for line in fp:
            buff = line.split(",")
            data.extend([(lambda s:s.strip('"'))(x) for x in buff])
    
    def sortData():
        data.sort()

    def worth(word):
        s = [(lambda x:ord(x)- 64)(ch) for ch in word]
        return sum(s)

    getData()
    sortData()
    loop = len(data)
    i=1
    total=0
    while(i<loop+1):
        total += i*worth(data[i-1])
        i += 1
    print(total)

def problem_23():
    def isAbundant(num):
        total = 1
        i = 2
        l = math.ceil(num**0.5)
        divs=list(filter(lambda x:num%x==0, range(2,l)))
        s = [(lambda x:num//x)(x) for x in divs]
        divs += s
        divs.append(1)
        if (l*l == num):
            divs.append(l)
        return sum(divs) > num

    count = 0
    i = 2
    #s = set([])
    #while (i<28124):
    #    if (isAbundant(i)):
    #        s.add(i)
    #    i+=1
    s = set(filter(lambda x:isAbundant(x), range(2,28124)))

    total = 0
    i = 1
    while (i<28124):
        found = False
        for x in s:
            y = i - x
            if (y <=0):
                continue
            if (y in s):
                found = True
                break
        if (not found):
            total += i
        i += 1
    print(total)

def problem_67():
    data = []
    dict = {}
    def getData():
        fp = open("problem67.txt", "r")
        for line in fp:
            line = line.rstrip()
            a = [int(x) for x in line.split()]
            data.append(a)

    getData()
    m = len(data[-1])
    for i in range(m):
        for j in range(i+1):
            left = 0
            right = 0
            if (j>0):
                left = dict[(i-1,j-1)]
            if (j<i):
                right = dict[(i-1,j)]
            parent = max(left, right)
            dict[(i,j)] = parent + data[i][j]
    maxvalue = max(dict.values())
    print(maxvalue)

if __name__ == "__main__":
    #problem_13()
    #problem_15()
    #problem_16()
    #problem_17()
    #problem_18()
    #problem_19()
    #problem_22()
     problem_23()
    #problem_67()