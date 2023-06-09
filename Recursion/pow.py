def power(N,R):
        if R == 0:
            return 1
        else:
            ans = power(N, R-1)
            return ans*N

print(power(2, 3 ))