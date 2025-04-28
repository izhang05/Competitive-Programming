n = int(input())
a, b = [int(x) for x in input().split()]
c, d = [int(x) for x in input().split()]

visited = [[[False, False] for j in range(n)] for i in range(n)]

stack = [(0,0,0), (0,0,1)]
while len(stack) > 0:
    i, j, t = stack.pop()

    if visited[i][j][t]:
        continue
    visited[i][j][t] = True

    if t == 0:
        di, dj = a,b
    else:
        di, dj = c,d

    deltas = [
        (di,dj),
        (-di,dj),
        (di,-dj),
        (-di,-dj),
        (dj,di),
        (-dj,di),
        (dj,-di),
        (-dj,-di),
    ]

    for dx, dy in deltas:
        x, y = i+dx, j+dy
        if x < 0 or x >= n or y < 0 or y >= n:
            continue

        stack.append((x,y,1-t))

count = 0
for i in range(n):
    for j in range(n):
        flag = visited[i][j][0] or visited[i][j][1]
        if flag:
            count += 1

print(count)
 