puzzle = 'abcabcbacabcd'
target = 'abcd'

j=0
count = 0
i = 0

while i < len(puzzle):
    print(puzzle[i]+'=='+target[j])
    if puzzle[i] == target[j]:
        # print(puzzle[i]+'=='+target[j])
        count+=1
        j+=1
        if count == len(target):
            print("Pattern Found")
            exit()
    else:
        j = j-count
        if count != 0:
            i-=1
            print("i",i)
        count = 0
    
    i+=1


