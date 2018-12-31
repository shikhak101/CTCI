def substr(s1,s2):
    substring = 0
    if s2 in s1:
        substring = 1
    if substring == 1:
        print "s2 is rotation of s1"
    else:
        print "s2 is not rotation of s1"
s1 = raw_input("String 1 : ")
s2 = raw_input("String 2 : ")
substr(s1+s1,s2)