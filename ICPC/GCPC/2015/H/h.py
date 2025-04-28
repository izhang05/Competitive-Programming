n = int(input())

stack = []
edges = dict()
for _ in range(n):
    name, k = input().split(' ')

    package, method = name.split('::')
    if method == "PROGRAM":
        stack.append(name)
    if not name in edges:
        edges[name] = set()

    if k == 0:
        input()
        continue
    
    names = input().split(' ')
    for name2 in names:
        if not name2 in edges:
            edges[name2] = set()
        edges[name2].add(name)

visited = set()
while len(stack) > 0:
    name = stack.pop()
    if name in visited:
        continue
    visited.add(name)

    for name2 in edges[name]:
        stack.append(name2)

print(n - len(visited))

