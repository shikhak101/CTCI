def rotate(m,n):
    length = int(n/2)
    for row in range(length):
        for col in range(n-row-1):
            temp = m[row][col]
            m[row][col] = m[n-col-1][row]
            m[n-col-1][row] = m[n-row-1][n-col-1]
            m[n-row-1][n-col-1] = m[col][n-row-1]
            m[col][n-row-1] = temp
    print m
m = [[1,2,3],[4,5,6],[7,8,9]]
rotate(m,3)