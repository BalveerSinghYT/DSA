
in_list = list(map(int, list(input("Enter the no.: ").split(" "))))

# print(in_list)
new_list = []

for i in in_list:
    square = i**2
    # print(square)
    new_list.append(square)

new_list.sort()
print(new_list)