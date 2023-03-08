'''
Create class EMPLOYEE for storing details
(Name, Designation, gender, Date of Joining and Salary).
Define function members to compute
a)total number of employees in an organization
b) count of male and female employee
c) Employee with salary more than 10,000
d) Employee with designation Asst Manager 
'''
class Employee:
	totalEmployee = 0
	males = 0
	females = 0


	def __init__(self,name,designation,gender,doj,salary):
		self.name = name
		self.designation = designation
		self.gender = gender
		self.doj = doj
		self.salary = salary
		Employee.totalEmployee += 1
		if self.gender == 'M':
			Employee.males += 1
		else:
			Employee.females += 1


	
	def totalEmployeeCount():
		return Employee.totalEmployee


	
	def genderCount():
		print('Males:',Employee.males)
		print('Females:',Employee.females)


	def isSalaryGreater10000(self):
		if self.salary > 10000:
			return True
		else:
			return False 


	def isAsstManager(self):
		if self.designation == "Asst Manager":
			return  True
		else:
			return False


def create():
	name = input("Name: ")
	designation = input("Designation: ")
	gender = input("Gender(M/F): ")
	
	doj = input('Enter a date in YYYY-MM-DD format')
	salary = int(input("Salary: "))
	emp = Employee(name,designation,gender,doj,salary)
	return emp



emp_list = []
while(1):
	print("1.Create Employee\n2.Total Employees\n3.Gender count\n4.Employee with salary > 10000\n5.Asst Managers")
	
	choice = int(input("Enter your choice: "))
	if choice == 1:
		emp_list.append(create())
	elif choice == 2:
		print(Employee.totalEmployeeCount())
	elif choice == 3:
		print(Employee.genderCount())
	elif choice == 4:
		for emp in emp_list:
			if emp.isSalaryGreater10000():
				print(emp.name)
	elif choice == 5:
		for emp in emp_list:
			if emp.isAsstManager():
				print(emp.name)
	else:
		print("Invalid choice")





