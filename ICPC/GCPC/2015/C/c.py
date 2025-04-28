args = input().split()
a = float(args[0])
n = int(args[1])

coords = []
for _ in range(n):
    x,y = [int(t) for t in input().split()]
    coords.append((x,y))

total_area = 0
for i in range(n):
    x1,y1 = coords[i-1]
    x2,y2 = coords[i]

    total_area += x1*y2
    total_area -= x2*y1
total_area = abs(total_area) / 2

low = 2
high = 1000
while high-low > 0.000001:
    s = (high+low) / 2

    subtract = 0
    for i in range(n):
        x,y = coords[i-1]
        x1,y1 = coords[i-2]
        x2,y2 = coords[i]

        dx1 = x1-x
        dx2 = x2-x
        dy1 = y1-y
        dy2 = y2-y

        det = abs(dx1*dy2-dx2*dy1)
        area = 1/(s*s) * det / 2

        subtract += area
    
    ratio = 1 - subtract / total_area

    if ratio > a:
        high = s
    else:
        low = s

print(s)
