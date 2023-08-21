"""
Name: Kushal Kishor Shankhapal
Roll no: 57
Branch: IT-3
Date: 19/01/2023
Assingnment no: 5 (Written)
Assingnment Name: 
Program for performing various String Operations.
"""

s = input("Enter a string: ")

while(1):
    print("*******************************")
    print("1. Calculate length of string\n2. String reversal\n3. Equality check of two strings\n4. Check palindrome\n5. Check substring")
    choice = int(input("Enter your Choice: "))

    if choice == 1:
        print("Length of the string is", len(s), "\n")

    elif choice == 2:
        print("Reverse of the string is: ", s[::-1], "\n")

    elif choice == 3:
        s2 = input("Enter a string to compare: \n")

        if s == s2:
            print("Strings are Equal. \n")
        else:
            print("Strings are not Equal \n")
    
    elif choice == 4:
        if s == s[::-1]:
            print("String is a Palindrome. \n")
        else:
            print("String is not a Palindrome. \n")
    
    elif choice == 5:
        sub = input("Enter a substring to compare: \n")
        if sub in s:
            print(sub, "is present in", s, "\n")
        else:
            print(sub, "is not present in", s, "\n")
    
    else:
        print("\nInvalid Choice! Exiting Programme.")
        exit()
"""
Output:

Enter a string: madam
*******************************
1. Calculate length of string
2. String reversal
3. Equality check of two strings
4. Check palindrome
5. Check substring
Enter your Choice: 1
Length of the string is 5 

*******************************
1. Calculate length of string
2. String reversal
3. Equality check of two strings
4. Check palindrome
5. Check substring
Enter your Choice: 2
Reverse of the string is:  madam 

*******************************
1. Calculate length of string
2. String reversal
3. Equality check of two strings
4. Check palindrome
5. Check substring
Enter your Choice: 3
Enter a string to compare: 
Madam
Strings are not Equal 

*******************************
1. Calculate length of string
2. String reversal
3. Equality check of two strings
4. Check palindrome
5. Check substring
Enter your Choice: 4
String is a Palindrome. 

*******************************
1. Calculate length of string
2. String reversal
3. Equality check of two strings
4. Check palindrome
5. Check substring
Enter your Choice: 5
Enter a substring to compare: 
mad
mad is present in madam 

*******************************
1. Calculate length of string
2. String reversal
3. Equality check of two strings
4. Check palindrome
5. Check substring
Enter your Choice: 9

Invalid Choice! Exiting Programme.
"""
