
def sum(number):
    sum=0
    while (number > 0):
        k = number % 10
        sum += k
        number = number // 10
    return sum

def main():
    number = 1
    for i in range(1, 101):
        number *= i
    a = sum (number)
    print (a)

if __name__ == "__main__":
    main()