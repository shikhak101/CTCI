def zeromat(m):
    for i in range(len(m)):
        for j in range(len(m[i])):
            if m[i][j] == 0:
                for j1 in range(len(m[i])):
                    m[i][j1] = float('-inf')
                for i1 in range(len(m)):
                    m[i1][j] = float('-inf')
    for i in range(len(m)):
        for j in range(len(m[i])):
            if m[i][j] == float('-inf'):
                m[i][j]=0
    print m
m = [[1,2,3,8],[2,4,0,6],[0,4,3,7]]
zeromat(m)
