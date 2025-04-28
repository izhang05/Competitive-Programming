n = int(input())

flag = True
prev = (-1, -1)
for _ in range(n):
    a, b = [int(x) for x in input().split()]
    x, y = prev

    if a < x or b < y:
        flag = False

    prev = (a,b)

if flag:
    print('yes')
else:
    print('no')