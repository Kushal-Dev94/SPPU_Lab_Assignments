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
    def __init__(self, name, rollNo, marks):
        self.name = name
        self.marks = marks
        self.rollNo = rollNo
    
    def msg(self):
        print(self.name, "with roll no.", self.rollNo, "got", self.marks, "marks")

s1 = student("Abcd", 12, 30)
s2 = student("Pqrs", 10, 25)
s1.msg()
s2.msg()

"""
Output:

Abcd with roll no. 12 got 30 marks
Pqrs with roll no. 10 got 25 marks
"""