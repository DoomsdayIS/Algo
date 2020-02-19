P = open("smallsort.in",'r')
M = open("smallsort.out",'w')
import random
import sys
sys.setrecursionlimit(10**8)
def qsort(left, right):
    if left >= right:
        return
    x = a[random.randint(left, right)]
    i = left
    j = right
    while i < j:
        while a[i] < x:
            i = i + 1
        while a[j] > x:
            j = j - 1
        if i > j:
            break
        a[i],a[j] = a[j],a[i]
        i = i + 1
        j = j - 1
    qsort(left, j)
    qsort(i, right)
n = P.readline()
n = int(n)
b = P.readline()
a = list(map(int,b.split()))
left = 0
right = n - 1
qsort(left, right)
ans = ''
for i in a:
    ans += str(i) + ' '
M.write(ans)
P.close()
M.close()