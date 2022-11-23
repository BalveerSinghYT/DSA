a = [-4, -3, 2, -4, -3, 1]

b = []
for i in a:
    square = i**2
    b.append(square)
    print(id(i))
print(b)
for j in b:
    print(id(j))