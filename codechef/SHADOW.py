from math import floor, ceil

def gcd(a, b):
    
    if a > b:
        t = a
        a = b
        b = t
    
    if a == 0:
        return b
    
    return gcd(b % a, a)

def lcm(a, b):

    return int((a * b) / gcd(a, b))

def get_val(n1, n2, x):

    return int(( (n2 * (n2 + 1)) / 2 - (n1 * (n1 - 1)) / 2 ) * x)

def solve(a, b, l, r):

    if l > r:

        PS = 0
        other = 0
        print("TRUE LOVE")
        return
    elif l == r:

        PS = 0
        if l % a == 0:
            PS += l
        if l % b == 0:
            PS += l
        
    else:

        n1 = int(ceil(l / a))
        n2 = int(floor(r / a))
        val1 = get_val(n1, n2, a)

        n1 = int(ceil(l / b))
        n2 = int(floor(r / b))
        val2 = get_val(n1, n2, b)

        PS = val1 + val2
    
    lcm_val = lcm(a, b)
    n1 = int(ceil(l / lcm_val))
    n2 = int(floor(r / lcm_val))
    other = get_val(n1, n2, lcm_val)

    flag1 = flag2 = False

    if abs(PS - other) % 2 == 0:
        flag1 = True
    
    if (PS % 2 == 0) or (PS % 3 == 0):
        flag2 = True
    
    if flag1 and flag2:
        print("TRUE LOVE")
    elif flag1 or flag2:
        print("LOVE")
    else:
        print("FAKE LOVE")

def main():

    t = int(input())
    
    for i in range(t):
        line_arr = input("").split()
        line_arr = [int(x) for x in line_arr]
        a, b, l, r = line_arr

        solve(a, b, l, r)


main()