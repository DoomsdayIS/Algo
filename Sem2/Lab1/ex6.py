P = open("input.txt",'r')
M = open("output.txt",'w')

def BFS(start,n,m):
    dynamic = [start]
    left = 0
    while left < len(dynamic):
        if (dynamic[left] % m != 0):
            if (maze[(dynamic[left] - 1)// m][(dynamic[left] - 1) % m] == '.' or
                    maze[(dynamic[left] - 1)// m][(dynamic[left] - 1) % m] == 'T') and way[(dynamic[left] - 1)][1] == -1:
                way[dynamic[left] - 1] = ['L', dynamic[left]]
                dynamic.append(dynamic[left] - 1)
        if (dynamic[left] % m != m - 1):
            if (maze[(dynamic[left] + 1) // m][(dynamic[left] + 1) % m] == '.' or
            maze[(dynamic[left] + 1) // m][(dynamic[left] + 1) % m] == 'T') and way[(dynamic[left] + 1)][1] == -1:
                way[dynamic[left] + 1] = ['R', dynamic[left]]
                dynamic.append(dynamic[left] + 1)
        if (dynamic[left] // m != 0):
            if (maze[(dynamic[left] - m) // m][(dynamic[left] - m) % m] == '.' or
                maze[(dynamic[left] - m) // m][(dynamic[left] - m) % m] == 'T') and way[(dynamic[left] - m)][1] == -1:
                way[dynamic[left] - m] = ['U', dynamic[left]]
                dynamic.append(dynamic[left] - m)
        if (dynamic[left] // m != n - 1):
            if (maze[(dynamic[left] + m) // m][(dynamic[left] + m) % m] == '.' or
                maze[(dynamic[left] + m) // m][(dynamic[left] + m) % m] == 'T') and way[(dynamic[left] + m)][1] == -1:
                way[dynamic[left] + m] = ['D', dynamic[left]]
                dynamic.append(dynamic[left] + m)
        left += 1

gg = P.readline()
n,m = map(int,gg.split())
maze = []
way = [['N', -1] for i in range(m*n)]
for i in range(n):
    buffer = P.readline()
    if 'S' in buffer:
        start = buffer.index('S') + i*m
    if 'T' in buffer:
        end = buffer.index('T') + i*m
    maze.append(buffer)
BFS(start,n,m)
if way[end][1] == -1:
    M.write('-1')
else:
    ans = ''
    lenght = 0
    buffer = end
    while buffer != start:
        ans += way[buffer][0]
        lenght += 1
        buffer = way[buffer][1]
    M.write(str(lenght) + '\n')
    M.write(ans[::-1])
P.close()
M.close()