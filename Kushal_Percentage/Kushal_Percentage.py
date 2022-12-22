"""
Name: Kushal Kishor Shankhapal
Roll no: 57
Branch: IT-3
Date: 24/12/2022
Assingnment no: 2
Assingnment Name: 
To calculate the total percentage of marks obtained by a student after accepting the
marks obtained in the 5 subjects.
"""

name = input("Input the students's name: ")
Engg_maths = int(input("Input the marks obtained in Engg. Maths: "))
Engg_chem = int(input("Input the marks obtained in Engg. Chemistry: "))
BEE = int(input("nput the marks obtained in BEE: "))
SME = int(input("nput the marks obtained in SME: "))
EVS = int(input("nput the marks obtained in EVS: "))
Total_marks = Engg_maths + Engg_chem + BEE + SME + EVS
Total_percentage = round((Total_marks / 500) * 100, 2)
print("The total percentage of marks obtained by " + name + " is " + str(Total_percentage)) 

"""
Output: 

cc-25@cc25-OptiPlex-3010:~/Desktop/Kushal_Files$ python3 Kushal_Percentage.py
Input the students's name: Kushal
Input the marks obtained in Engg. Maths: 99
Input the marks obtained in Engg. Chemistry: 98
nput the marks obtained in BEE: 95
nput the marks obtained in SME: 97
nput the marks obtained in EVS: 98
The total percentage of marks obtained by Kushal is 97.4
cc-25@cc25-OptiPlex-3010:~/Desktop/Kushal_Files$ 
"""