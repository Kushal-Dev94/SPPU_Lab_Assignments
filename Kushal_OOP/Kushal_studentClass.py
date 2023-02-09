"""
Name: Kushal Kishor Shankhapal
Roll no: 57
Branch: IT-3
Date: 09/02/2023
Assingnment no: Practice
Assingnment Name:
Student Class
"""

class student:
    def __init__(self, name, marks):
        self.name = name
        self.marks = marks
    
    def msg(self):
        print(self.name, "got", self.marks, "marks")

s1 = student("Abcd", 30)
s2 = student("Pqrs", 25)
s1.msg()
s2.msg()

"""
Output:

Abcd got 30 marks
Pqrs got 25 marks
"""