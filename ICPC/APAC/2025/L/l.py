n, m, t, p = [int(x) for x in input().split()]

grid = []
for _ in range(n):
    row = [int(x) for x in input().split()]
    grid.append(row)

possible = [0 for _ in range(t+1)]
for i in range(n):
    for j in range(m):
        x = grid[i][j]
        if x == 0:
            continue

        for ni, nj in [(i+1,j),(i-1,j),(i,j+1),(i,j-1)]:
            if ni < 0 or nj < 0 or ni >= n or nj >= m:
                continue
            x = grid[i][j]
            y = grid[ni][nj]
            if y == 0:
                continue
            if y < x:
                x,y = y,x
            
            if x > p:
                continue
            out = y + (p-x)
            if out <= t:
                possible[out] = 1
                # print(x,y,out)

            if y > p:
                continue
            out = x + (p-y)
            if 1 <= out <= t:
                possible[out] = 1
                # print(x,y,out)

possible[p] = 0
possible[0] = 0
out = sum(possible)
# sprint(possible)
print(f"{out}/{t-1}")