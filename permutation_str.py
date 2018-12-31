def perm(s1,s2):
    modified_s2 = s2
    permutation = 0
    for i in s1:
        if s1.count(i) == s2.count(i):
            continue
        else:
            permutation = -1
            break
    if permutation == 0:
        print "one is permutation of another"
    else:
        print "not a permutation of one another"
s1 = raw_input("String 1 : ")
s2 = raw_input("String 2 : ")
perm(s1,s2)