args = [int(x) for x in input().split()]

uses = args[0::2]
rests = args[1::2]

us, rs, ts = [], [], []
for _ in range(10):
    u,r,t = [int(x) for x in input().split()]
    us.append(u)
    rs.append(r)
    ts.append(t)

time = 0
for _ in range(3):
    for i in range(10):
        u = us[i]
        r = rs[i]
        t = ts[i]

        use = uses[i]
        rest = rests[i]

        if time < t:
            time += use
            if time >= t:
                t = time
            time += rest
        else:
            offset = time-t
            modulo = offset // (u+r)
            cycle_start = t + modulo * (u+r)

            if cycle_start <= time < cycle_start+u:
                time = cycle_start + u
            else:
                pass
            
            time += use
            if time >= cycle_start + u + r:
                t = time
            time += rest

        ts[i] = t

time -= rests[-1]
print(time)