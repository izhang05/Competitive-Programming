n, m = [int(x) for x in input().split()]
cals = [int(x) for x in input().split()]

caps = [m]
for _ in range(n):
    cap = caps[-1]
    cap = (2 * cap) // 3
    caps.append(cap)

dp = [0 for _ in range(n+1)]

for i in range(n):
    dp_new = [0 for _ in range(n+1)]
    c = cals[i]

    maximum = 0
    for j in range(n+1):
        maximum = max(maximum,dp[j])
    dp_new[0] = maximum

    for j in range(1,n+1):
        dp_new[j] = dp[j-1] + min(caps[j-1], c)
    
    dp = dp_new

print(max(dp))
