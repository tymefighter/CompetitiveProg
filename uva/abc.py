x = int(input(""))
alpha = int(input(""))
n = int(input(""))
c = int(input(""))

val1 = (pow(alpha, n, c) * ((x - 1) % c)) % c
val2 = ((pow(alpha, n, c) - 1) * pow(alpha - 1, c - 2, c) * alpha) % c

ans = (val1 - val2) % c

if ans < 0:
    ans += c

print(ans)