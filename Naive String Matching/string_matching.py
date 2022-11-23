puzzle = 'abcbbac'
target = 'ac'

j=0
count = 0
for i in range(len(puzzle)):
    # print(puzzle[i]+'=='+target[j])
    if puzzle[i] == target[j]:
        print(puzzle[i]+'=='+target[j])
        count+=1
        j+=1
        
        if count == len(target):
            print("Pattern Found")
            exit()
    else:
        j = j-count
        count = 0

