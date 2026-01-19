from math import atan2, pi

tau = 2 * pi
eps = 0.000000001

t = int(input())

def within(start, end, x):
    if start-eps <= x <= end+eps:
        return True
    # if start-eps <= x+1 <= end+eps:
    #     return True
    return False

for _ in range(t):
    n = int(input())

    angles = []
    for _ in range(n):
        x, y = [int(x) for x in input().split()]

        angle = atan2(y,x)
        angle /= tau
        angles.append((angle + 1) % 1.0)
    # angles = list(set(angles))
    # angles.sort()
    # for i in range(n):
    #     angles.append(angles[i]+1.0)
    # print(angles)

    events = [] # (time, toRemove)
    for angle in angles:
        events.append((angle,True))
        events.append((angle-0.5,False))
        events.append((angle+0.5,False))
    events.sort()

    minimum = 1000000000000000000
    count = 0
    for time, toRemove in events:
        if toRemove:
            count -= 1
        else:
            count += 1
        if 0.0 <= time and time <= 1.0:
            minimum = min(minimum, count)

    # i = 1
    # j = 1
    # # print(angles)
    # for k in range(n):
    #     start = angles[k] + 2 * eps
    #     end = start + 0.5

    #     while i < j and not within(start, end, angles[i]):
    #         count -= 1
    #         i = i+1

    #     while j < 2*n and within(start, end, angles[j]):
    #         count += 1
    #         j = j+1

    #     # count = 0
    #     # for x in range(2*n):
    #     #     if within(start, end, angles[x]):
    #     #         count += 1

    #     # print(start, end, count, i, j)

    #     minimum = min(minimum, count)
    
    print(minimum)