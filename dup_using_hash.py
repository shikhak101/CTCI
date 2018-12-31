def dup(s):
    
    arr = [0]*1000
    duplicate = 0
    for i in s:
        c = ord(i)
        arr[c] = arr[c] + 1
        if arr[c] > 1:
            duplicate = 1
            break
    if duplicate == 1:
        print "Duplicates are present"
    else :
        print "Duplicates are not present"

s = raw_input("String : ")
dup(s)