def pow(n):

    if n == 0:
        return 1

    if n % 2 == 0:
        val = pow(n / 2)
        return val * val
    else:
        return 2 * pow(n - 1)

def solve(s1, s2, t1, t2, x):

    d0 = int(s1 / pow(t1 - 1))
    ans = int(d0 * pow(x - 1))
    print(int(ans))


def main():

    t = int(input(""))

    for i in range(t):

        line_arr = input("").split()
        s1, s2, t1, t2 = line_arr
        s1, s2, t1, t2 = (int(s1), int(s2), int (t1), int(t2))
        x = int(input(""))

        solve(s1, s2, t1, t2, x)

if __name__ == "__main__":
    main()