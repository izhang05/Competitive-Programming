from math import factorial


def f(m, n):
    sol = 0.0
    cnt = 0
    for i in range(1, n + 1):
        if n % i != 0:
            continue
        cnt += 1
        sol += float(factorial(m * i)) / float(pow(factorial(i), m))
    # print(sol)
    # sol /= m
    sol /= cnt
    return sol


# print(f(2, 1), f(2, 2), f(3, 1), f(3, 2))
# exit(0)

mx = 1e15
sol = 0

for i in range(2, 1000):
    good = True
    for j in range(1, 1000):
        cur = f(i, j)
        print(i, j, cur)
        if cur > mx:
            if j == 1:
                good = False
            break
        sol += cur
    if not good:
        break

print(sol)
