m,n = [int(x) for x in input().split()]

grid = []
for _ in range(m):
    row = list(input())
    grid.append(row)

def dfs(x,y,grid):
    next = (x,y)
    while True:
        search = [
            (-1,-1),
            (-1,0),
            (-1,1),
            (0,-1),
            (0,1),
            (1,-1),
            (1,0),
            (1,1),
        ]

        flag = False
        for dx,dy in search:
            i,j = next[0]+dx, next[1]+dy
            if i < 0 or j < 0 or i >= m or j >= n:
                continue
            c = grid[i][j]

            if c != '#':
                continue

            next = (i,j)
            grid[i][j] = '.'
            flag = True
            break

        if not flag:
            break

# print(grid)
count = 0
for x in range(m):
    for y in range(n):
        c = grid[x][y]
        # print(grid)

        if c == '#':
            dfs(x,y,grid)
            count += 1

print(count)