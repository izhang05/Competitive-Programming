from math import sqrt

t = int(input())

def search(optx,r,w,h,C):
    opt = -1
    best = None
    for i in range(-1*C, C+1):
        x = optx + i

        if x < 0:
            continue
        
        ymax = 10 ** 10
        ymin = 0
        while ymax > ymin+1:
            y = (ymax + ymin) // 2
            if x*x * w*w + y*y * h*h > 4*r*r:
                ymax = y
            else:
                ymin = y

        # print(ymin, ymax)
        for y in [ymin, ymax]:
            if x*x * w*w + y*y * h*h > 4*r*r:
                continue

            if x*y >= opt:
                opt = x*y
                best = (x,y)
        
    return opt, best

for _ in range(t):
    r, w, h = [int(x) for x in input().split()]

    optx = int(sqrt(2) * r / w)
    opty = int(sqrt(2) * r / h)

    C = 100
    opt = -1
    best = None

    opt, best = search(optx, r, w, h, C)
    
    opt2, best2 = search(opty, r, h, w, C)

    if opt2 > opt:
        opt = opt2
        best = (best2[1], best2[0])
    
    assert(opt >= 0)


    optx = sqrt(2) * r / w
    opty = sqrt(2) * r / h
    # print(best, (optx, opty))
    x,y = best
    # print(x*x * w*w + y*y * h*h, 4*r*r)

    print(int(opt))

