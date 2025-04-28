g, c, n = [int(x) for x in input().split()]

dp = [[-1 for _ in range(2*(g+1))] for _ in range(c+1)]
dp[c][0] = 0

for _ in range(n):
    dp_new = [[dp[i][j] for j in range(2*(g+1))] for i in range(c+1)]

    merchant, p, s = input().split()
    p = int(p)
    s = int(s)

    for a in range(c+1):
        for b in range(2*(g+1)):
            if dp[a][b] == -1:
                continue
            
            if b >= s:
                dp_new[a][b-s] = max(dp_new[a][b-s], dp[a][b]+1)
            elif a >= 1:
                remaining = g - s
                k = remaining // p

                low = k * p
                high = (k+1) * p

                change = -1
                if merchant == 'generous':
                    change = high
                elif merchant == 'greedy':
                    change = low
                elif merchant == 'honest':
                    if 2*change >= high+low:
                        change = high
                    else:
                        change = low
                else:
                    assert False, 'whoops'
                
                # print(a,b,change)
                dp_new[a-1][b+change] = max(dp_new[a-1][b+change], dp[a][b]+1)
    
    dp = dp_new
    # print(dp)

out = 0
for row in dp:
    out = max(out,max(row))

print(out)
