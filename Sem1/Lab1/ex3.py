def iwannadie(x,y):
    if x - 1 < 0:
        return nl[y+1][x]
    elif y + 1 > h-1:
        return nl[y][x-1]
    else:
        return max(nl[y][x-1],nl[y+1][x])
P = open("turtle.in",'r')
M = open("turtle.out",'w')
d = P.readline()
h,w = map(int,d.split())
nl = []
for i in range(h):
    d = P.readline()
    s = list(map(int,d.split()))
    nl.append(s)
x,y = 0,h-1
for i in range(1,h + w - 1):
    x1 = min(i,w-1)
    y1 = i - x1
    while y1 >= 0 and y >=y1 and x1 >= 0:
        ct = iwannadie(x+x1,y-y1)
        nl[y-y1][x+x1] += ct
        x1 -= 1
        y1 += 1
ans = str(nl[0][w-1])
M.write(ans)
P.close()
M.close()

