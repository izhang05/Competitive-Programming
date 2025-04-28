args = input().split(' ')
args = [int(x) for x in args]

n, k = args

flag = False
for modulo in range(2, 2*n+1, 5):
    for i in range(1, n+1):
        if flag:
            break
        j = modulo - i

        if j < 1 or j > n:
            continue

        print(i, j)
        result = input()

        if result == 'miss':
            continue
        elif result == 'sunk':
            k -= 1
            if k == 0:
                flag = True
                break
            continue
        elif result == 'hit':
            pairs = [
                (0,1),
                (0,2),
                (0,3),
                (0,4),
                (0,-1),
                (0,-2),
                (0,-3),
                (0,-4),
                (1,0),
                (2,0),
                (3,0),
                (4,0),
                (-1,0),
                (-2,0),
                (-3,0),
                (-4,0),
            ]

            for di, dj in pairs:
                if flag:
                    break
                a = i+di
                b = j+dj

                if a < 1 or a > n or b < 1 or b > n:
                    continue

                print(a,b)
                result = input()

                if result == 'sunk':
                    k -= 1
                    if k == 0:
                        flag = True
                        break                           

        