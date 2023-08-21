"""
Name: Kushal Kishor Shankhapal
Roll no: 57
Branch: IT-3
Date: 12/12/2022
Assingnment no: Practice Test
Assingnment Name:
Write a program to accept a number from user, and display that many terms of the Fibonacci Series.
"""

num = int(input("How many terms of the Fibonacci Series do you want to see ? : "))
num -= 2
series = [0,1]
current_index = 1
while current_index <= num:
    series.append(series[current_index] + series[current_index - 1])
    current_index += 1

print("First" , num + 2, "terms of Fibonacci series: ", series)

"""
Output: 

cc-25@cc25-OptiPlex-3010:~/Desktop/Kushal_Files$ /bin/python3 /home/cc-25/Desktop/Kushal_Files/Kushal_Fibonacci.py
How many terms of the Fibonacci Series do you want to see ? : 10
First 10 terms of Fibonacci series:  [0, 1, 1, 2, 3, 5, 8, 13, 21, 34]
cc-25@cc25-OptiPlex-3010:~/Desktop/Kushal_Files$
"""