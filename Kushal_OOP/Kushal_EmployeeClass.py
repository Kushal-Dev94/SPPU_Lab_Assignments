"""
Name: Kushal Kishor Shankhapal
Roll no: 57
Branch: IT-3
Date: 09/02/2023
Assingnment no: Practice
Assingnment Name:
Student Class
"""

class employee:
    def __init__(self,name, age, exp, salary, qualification):
        self.name = name
        self.age = age
        self.exp = exp
        self.salary = salary
        self.qualification = qualification
        

    def display(self):
        print("Name:", self.name)
        print("Age (years):", self.age)
        print("Years of Experience:", self.exp)
        print("Salary (Rs):", self.salary)
        print("Qualification:", self.qualification)
    
E1 = employee("Kashish", 23, 3, 70000, "Phd in Machine Learning")
E1.display()

"""
Output:

Name: Kashish
Age (years): 23
Years of Experience: 3
Salary (Rs): 70000
Qualification: Phd in Machine Learning
"""