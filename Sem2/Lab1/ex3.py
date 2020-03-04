P = open("input.txt",'r')
M = open("output.txt",'w')
b = P.readline()
n,m = map(int,b.split())
matrix = [[0 for i in range(n)] for j in range(n)]
p_r = 0
for i in range(m):
    b = P.readline()
    start,end = map(int,b.split())
    if matrix[start - 1][end - 1] == 1 or matrix[end - 1][start - 1] == 1:
        p_r += 1
    matrix[start -1][end - 1] = 1
    matrix[end - 1][start - 1] = 1
if p_r > 0:
    M.write("YES")
else:
    M.write("NO")
P.close()
M.close()