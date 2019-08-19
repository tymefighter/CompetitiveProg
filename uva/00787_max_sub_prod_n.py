from sys import stdin

def solve(a):
    prod = 1
    max_val1 = a[0]

    for x in a:
        prod = prod * x
        max_val1 = max(prod, max_val1)
        if x == 0:
            prod = 1


     
    a.reverse()
    max_val2 = a[0]
    prod = 1
    for x in a:
        prod = prod * x
        max_val2 = max(prod, max_val2)
        if x == 0:
            prod = 1

    return max(max_val1, max_val2)

def main():

    a = []
    for line in stdin:

        for x in line.split():
            x = int(x)
            if x == -999999:
                print(solve(a))
                a = []
            else:
                a.append(x)


if __name__ == '__main__':

    main()