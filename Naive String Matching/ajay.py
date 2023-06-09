a = "abcabcfasgaubclkt"
b = "abcd"

for i in range(0,(len(a)-len(b))):
    count = 0
    for j in range(len(b)):
        if b[j] == a[j]:
            count+=1
    if count == len(b):
        print("found")
        break
    else:
        a = a[1:]
