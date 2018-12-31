def url(s,l):
    c = 1
    for i in range(len(s)):
        if s[i] == ' ' and c<l:
            s = s.replace(s[i],"%20",1)
            c += 1
    print s
s = raw_input("String : ")
l = input("Length : ")
url(s,l)