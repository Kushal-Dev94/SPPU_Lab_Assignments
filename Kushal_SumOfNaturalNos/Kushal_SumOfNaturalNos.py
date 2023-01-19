n = int(input("Enter a number: "))
sum = 0

for i in range(n):
    sum += i+1

print("Sum of first " + str(n) + " natural numbers is", sum)

"""
Output:
Enter a number: 5
Sum of first 5 natural numbers is 15
"""