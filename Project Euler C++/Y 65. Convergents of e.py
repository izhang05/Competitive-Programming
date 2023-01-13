import math

co = [2]


def solve(x, num, den):
    if x < 0:
        return (num, den)
    num, den = den, num
    num += co[x] * den
    g = math.gcd(num, den)
    num //= g
    den //= g
    return solve(x - 1, num, den)


n = 100
for i in range(1, n):
    if i % 3 != 2:
        co.append(1)
    else:
        co.append(2 * ((i + 1) // 3))

num, den = solve(n - 2, co[n - 1], 1)
print(num)
sol = 0
while (num > 0):
    sol += num % 10
    num //= 10

print(sol)
