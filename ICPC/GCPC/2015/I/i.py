w, s = [int(x) for x in input().split()]
x, y = [int(t) for t in input().split()]

heights_all = []
for _ in range(w):
    heights = [int(t) for t in input().split()]
    heights_all.append(heights)
    
cuts = [0] * x
for _ in range(s):
    cuts_new = [int(t) for t in input().split()]
    for i in range(x):
        cuts[i] = max(cuts[i], cuts_new[i])

for j in range(w):
    heights = heights_all[j]
    for i in range(x):
        heights[i] = min(heights[i], y - cuts[i])
    print(' '.join([str(t) for t in heights]))