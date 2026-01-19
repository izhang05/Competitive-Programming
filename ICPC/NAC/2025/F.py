t = int(input())

for k in range(t):
    if k > 0:
        print()

    n, m, u, r, d, l = [int(x) for x in input().split()]

    if u < n-1 or r < m-1:
        print("impossible")
        continue

    u -= n-1
    r -= m-1
    area = d+r

    out = [['.' for _ in range(m)] for _ in range(n)]
    flag = False
    # for _ in range(n):
    #     if area >= m-1:
    #         out.append(('.' * (m-1)) + 'U')
    #         area -= m-1
    #         continue

    #     if flag:
    #         out.append('U' + ('.' * (m-1)))
    #         continue

    #     out.append(('.' * area) + ('R' * (m-1-area)) + 'U')
    #     flag = True
    #     area = 0

    i = 0
    j = m-1
    last = 'U'
    while i <= n-1 and j >= 0:
        out[i][j] = last

        # print(i,j,area)

        if area >= j:
            i += 1
            last = 'U'
            area -= j
        # elif area == 0:
        #     i += 1
        #     last = 'U':
        else:
            j -= 1
            last = 'R'


    # print()
    # for row in out:
    #     print(row)
        
    for i in range(n):
        out[i] = list(out[i])
    
    for i in range(n):
        for j in range(m):
            if out[i][j] != '.':
                continue

            if r > 0:
                out[i][j] = 'R'
                r -= 1
            elif d > 0:
                out[i][j] = 'D'
                d -= 1
            elif u > 0:
                out[i][j] = 'U'
                u -= 1
            elif l > 0:
                out[i][j] = 'L'
                l -= 1
            else:
                assert(False)

    out[0][m-1] = '*'

    for row in out:
        print(''.join(row))

