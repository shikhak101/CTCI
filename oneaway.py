def diff(s1,s2):
    away = 0
    for i in s1:
        if s1.count(i) == s2.count(i) - 1:
            away += 1
        elif s1.count(i) == s2.count(i) + 1:
            away += 1
    if away == 0:
        if len(s2)-len(s1) == 1:
            away +=1 
    if away == 1:
        print "True"
    else :
        print "False"

s1 = raw_input("String 1 : ")
s2 = raw_input("String 2 : ")
diff(s1,s2)