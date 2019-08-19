import sympy

s = set({})
primes = list(sympy.primerange(899000000, 999000000))
# print(primes)
val = None

# for x in range(999999733, 1000000000):

#     flag2 = False
#     for y in range(999999491, 1000000000):
#         s = set({})
#         v1 = x * x
#         v2 = y * y

#         flag = True
#         val = None
        
#         for p in primes:
#             if (v1 % p, v2 % p) in s:
#                 flag = False
#                 val = p
#                 break
#             s.add((v1 % p, v2 % p))
        
#         print(x, y, val, flag)
#         if flag:
#             flag2 = True
#             break

#     if flag2:
#         break

        