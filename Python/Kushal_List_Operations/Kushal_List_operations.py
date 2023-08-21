"""
Name: Kushal Kishor Shankhapal
Roll no: 57
Branch: IT-3
Date: 02/02/2023
Assingnment no: Practice Test
Assingnment Name:
Do various operations on list
"""

list1 = [1,2,3,4,2,6]
print("List is ", list1)

#1
print("1. Sliced List is ", list1[2:4])

#2
list1.append([5,6])
print("2. Appended List is ", list1)

#3
list1 = [1,2,3,4,2,6]
list1.insert(2, 2.5)
print("3. Inserted List is ", list1)

#4
list1 = [1,2,3,4,2,6]
list1.extend([7,8])
print("4. Extended list is", list1)

#5
list1 = [1,2,3,4,2,6]
print("5. The count of 2 in the list is", list1.count(2))

#6
print("6. The index of 3 in the list is", list1.index(3))

#7
list1.reverse()
print("7. The reversed List is", list1)

#8
list1 = [1,2,3,4,2,6]
list1.sort()
print("8. The sorted List is", list1)

#9
list1 = [1,2,3,4,2,6]
list2 = list1.copy()
print("9. Shallow copy of the list is ", list2)

#10
list1 = [1,2,3,4,2,6]
print("10. The popped item from the List is", list1.pop(), "and the new List is", list1)

#11
list1 = [1,2,3,4,2,6]
list1.clear()
print("11. The cleared List is", list1)

#12
list1 = [1,2,3,4,2,6]
list1.remove(2)
print("12. List with 2 removed is", list1)

#13
list1 = [1,2,3,4,2,6]
del list1[3]
print("13. List with 3rd Indexed deleted is",list1)

"""
Output:
List is  [1, 2, 3, 4, 2, 6]
1. Sliced List is  [3, 4]
2. Appended List is  [1, 2, 3, 4, 2, 6, [5, 6]]
3. Inserted List is  [1, 2, 2.5, 3, 4, 2, 6]
4. Extended list is [1, 2, 3, 4, 2, 6, 7, 8]
5. The count of 2 in the list is 2
6. The index of 3 in the list is 2
7. The reversed List is [6, 2, 4, 3, 2, 1]
8. The sorted List is [1, 2, 2, 3, 4, 6]
9. Shallow copy of the list is  [1, 2, 3, 4, 2, 6]
10. The popped item from the List is 6 and the new List is [1, 2, 3, 4, 2]
11. The cleared List is []
12. List with 2 removed is [1, 3, 4, 2, 6]
13. List with 3rd Indexed deleted is [1, 2, 3, 2, 6]
"""