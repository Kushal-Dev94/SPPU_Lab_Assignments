"""
Name: Kushal Kishor Shankhapal
Roll no: 57
Branch: IT-3
Date: 26/12/2022
Assingnment no: 8 (4 in written)
Assingnment Name: 
Write a Program to accept a number from user
& print its digits in reverse order.
"""

n = int(input("Enter a number: "))
rev = 0

while n > 0:
    rev = (rev * 10) + (n % 10)
    n = n // 10

print(rev)

"""
Output1:
Enter a number: 7835
5387

Output2:
Enter a number: 123
321
"""