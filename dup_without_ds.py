def dup(s):
    duplicate = 0
    for i in s:
        modified_s = s.replace(i,'')
        if len(modified_s) != len(s):
            duplicate = 1
            break
    if duplicate == 1:
        print "Duplicates are present"
    else:
        print "Duplicates are not present"

s = raw_input("String : ")
dup(s)