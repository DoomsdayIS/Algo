P = open("binsearch.in", 'r')
M = open("binsearch.out", 'w')


def binsearch(x):
    buffer = [-1, -1]
    if x < nl[0] or x > nl[n - 1]:
        ansl.append(buffer)
    else:
        left = 0
        right = n - 1
        while left < right - 1:
            mid = (right + left) // 2
            if nl[mid] < x:
                left = mid
            else:
                right = mid
        if nl[left] == x:
            right = left
        buffer[0] = right + 1
        if x + 1 > nl[n - 1]:
            left = n
        else:
            x = x + 1
            left = 0
            right = n - 1
            while left < right - 1:
                mid = (right + left) // 2
                if nl[mid] < x:
                    left = mid
                else:
                    right = mid
            left += 1
        buffer[1] = left
        if buffer[0] > buffer[1]:
            buffer = [-1, -1]
            ansl.append(buffer)
        else:
            ansl.append(buffer)


n = P.readline()
n = int(n)
b = P.readline()
nl = list(map(int, b.split()))
count = P.readline()
count = int(count)
b = P.readline()
cl = list(map(int, b.split()))
ansl = []
for i in range(count):
    binsearch(cl[i])
for i in range(count):
    ans = str(ansl[i][0]) + ' ' + str(ansl[i][1])
    M.write(ans + '\n')
P.close()
M.close()