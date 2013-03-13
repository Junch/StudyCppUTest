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

    #print(not isLeapYear(100))
    #print(isLeapYear(400))
    #print(isLeapYear(12))
    #print(not isLeapYear(101))
    #print(days(1900))
    #print(days(2000))
    #print(dict)
    print (daysFrom1900(1901,1))
    print (daysFrom1900(1902,1))
    print (daysFrom1900(1903,1))
    print (daysFrom1900(1904,1))
    print (daysFrom1900(1905,1))
    sundays=0
    for i in range(1901, 2000):
        for j in range(1, 12):
            days = daysFrom1900(i,j)
            if (days % 7 == 0):
                sundays += 1
                print("(%d,%d)"%(i,j))
    print (sundays)


if __name__ == "__main__":
    #problem_15()
    #problem_16()
    #problem_17()
    problem_19()