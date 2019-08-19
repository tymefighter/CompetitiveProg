n = None
k = None

def solve():

    global n, k

    b = k % n
    a = n - b

    if a == b:
        print(2 * min(a, b) - 1)
    else:
        print(2 * min(a, b))

def main():

    t = int(input(''))
    global n, k

    for i in range(t):
        n = int(input(''))
        k = int(input(''))
        solve()

if __name__ == "__main__":
    main()

