def comp(s):
    arr = [0]*200
    result = ""
    for i in s:
        c = ord(i)
        arr[c] += 1
    temp = s
    for i in range(len(arr)):
        if arr[i] != 0:
            result  = result + str(chr(i)) + str(arr[i])
    print result

s = raw_input("String : ")
comp(s)