args = [int(x) for x in input().split()]
n, m = args

grid = []
for _ in range(n):
    row = [int(x) for x in input().split()]
    grid.append(row)

arr2 = [[0 for _ in range(m)] for _ in range(n)]
for i in range(1, n):
    for j in range(1, m):
        comp = grid[i - 1][j - 1]
        val = arr2[i][j - 1] + arr2[i - 1][j] - arr2[i - 1][j - 1]
        if comp == grid[i][j - 1] and comp == grid[i - 1][j] and comp == grid[i][j]:
            val += 1
        arr2[i][j] = val

arr13 = [[0 for _ in range(m - 1)] for _ in range(n + 1)]
for i in range(1, n + 1):
    for j in range(1, m - 1):
        comp = grid[i - 1][j - 1]
        val = arr13[i][j - 1] + arr13[i - 1][j] - arr13[i - 1][j - 1]
        if comp == grid[i - 1][j] and comp == grid[i - 1][j + 1]:
            val += 1
        arr13[i][j] = val

arr31 = [[0 for _ in range(m + 1)] for _ in range(n - 1)]
for i in range(1, n - 1):
    for j in range(1, m + 1):
        comp = grid[i - 1][j - 1]
        val = arr31[i][j - 1] + arr31[i - 1][j] - arr31[i - 1][j - 1]
        if comp == grid[i][j - 1] and comp == grid[i + 1][j - 1]:
            val += 1
        arr31[i][j] = val

# for row in arr2:
#     print(row)
# for row in arr13:
#     print(row)
# for row in arr31:
#     print(row)

q = int(input())
for _ in range(q):
    x1, y1, x2, y2 = [int(x) for x in input().split()]

    if x2 - x1 >= 1 and y2 - y1 >= 1:
        val = arr2[x2][y2] - arr2[x1][y2] - arr2[x2][y1] + arr2[x1][y1]
        if val >= 1:
            # print("NO")
            print(1, val)
            continue

    if y2 - y1 >= 2:
        val = arr13[x2][y2 - 1] - arr13[x1][y2 - 1] - arr13[x2][y1] + arr13[x1][y1]
        if val >= 1:
            # print("NO")
            print(2, val)
            continue

    if x2 - x1 >= 2:
        val = arr31[x2 - 1][y2] - arr31[x1][y2] - arr31[x2 - 1][y1] + arr31[x1][y1]
        if val >= 1:
            # print("NO")
            print(3, val)
            continue

    print("YES")
