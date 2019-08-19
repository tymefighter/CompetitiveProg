
from math import ceil
VAL = 1000000007

def solve(n, k):

    if n >= k:
        return (k - 1) % VAL

    r = (k - 2) // (n - 1)


    return (k - 1) + (r * k) - ((n * r * (r + 1)) // 2) + ((r * (r - 1)) // 2)

def main():

    t = int(input(""))

    for i in range(t):

        n, k = input().split()
        n = int(n)
        k = int(k)

        print((solve(n, k)) % VAL)



if __name__ == "__main__":
    main()