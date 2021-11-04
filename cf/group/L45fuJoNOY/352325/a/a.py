t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split(" ")))
    value = 0
    if (a[0] == a[1]):
        value = a[0]
    elif (a[0] == a[2]):
        value = a[0]
    else:
        value = a[1]

    for i in range(len(a)):
        if (a[i] != value):
            print(i + 1)
            break
