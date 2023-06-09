def print_N(n):
    if n<=9:
            return 1
       
    return print_N(n//10)+1

print(print_N(123456789))