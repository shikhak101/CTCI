def palindromeperm(s):
    result = 0
    temp = s.replace(' ','')
    temp = temp.lower()
    length = 0
    for i in s:
        if i!=' ':
            length += 1

    letter = 0
    odd = 0
    if length % 2 == 0:
        for i in s:
            if s.count(i) != 2:
                result = -1
    else:
        c = 0
        for i in temp :
            if temp.count(i) == 2:
                letter+=1
            elif temp.count(i) == 1:
                odd += 1
            if i == ' ':
                break
        if letter == length -1 and odd == 1:
            result = 0
        else :
            result = -1
    if result == -1:
        print "False"
    else:
        print "True"
s = raw_input("String : ")
palindromeperm(s)