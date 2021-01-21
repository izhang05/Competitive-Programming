import math

mod = 1e9 + 7
n = int(input())
s5 = math.sqrt(5)
sol = ((pow((1 + s5) / 2, n, mod) - pow((1 - s5) / 2, n, mod)) / s5) % (mod)
print(int(sol))
