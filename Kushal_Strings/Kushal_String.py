"""
Name: Kushal Kishor Shankhapal
Roll no: 57
Branch: IT-3
Date: 05/12/2022
Assingnment no: 5
Assingnment Name: 
Write a Program to accept a string From User and perform following string operations:
    i) print complete string
    i)Print length of string
    iii) Print some charaters from the given string
    iv)Print substring using forward and backword indexing
    v)Perform String Concatenation
    vi)Perform String Repetition
"""

string = input("Enter a string: ")
print("The string is: ", string)
print("The length of the string is: ", len(string))
print("The first 5 characters in the string is: ", string[0:5])
print("A substring of the string (using forward indexing) is: ", string[7:22])
print("A substring of the string (using backward indexing) is: ", string[-22:-17])
print("String Concatenation: ", string + " And this is another string.")
print("The string is repeated 2 times: ", string * 2)

"""
Output:

cc-25@cc25-OptiPlex-3010:~/Desktop/Kushal_Files$ python3 Kushal_String.py
Enter a string: Hello, this is Python!
The string is:  Hello, this is Python!
The length of the string is:  22
The first 5 characters in the string is:  Hello
A substring of the string (using forward indexing) is:  this is Python!
A substring of the string (using backward indexing) is:  Hello
String Concatenation:  Hello, this is Python! And this is another string.
The string is repeated 2 times:  Hello, this is Python!Hello, this is Python!
cc-25@cc25-OptiPlex-3010:~/Desktop/Kushal_Files$ 
"""