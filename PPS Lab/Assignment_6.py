'''
Assignment No: 6
To count total characters in file, total words in file, total lines in file and frequency of 
given word in file. 
'''

searchWord = input("Enter word to search: ")
try:
    with open('ETC1.txt') as infile:
        words = 0
        characters = 0
        count = 0
        for lineno, line in enumerate(infile, 1):
            count += line.count(searchWord)
            wordslist = line.split()
            words += len(wordslist)
            characters += sum(len(word)for word in wordslist)
except FileNotFoundError:
    msg = "Sorry, the file does not exist."
    print(msg) 
print("Toatal lines::",lineno)
print("Total words ::",words)
print("Total characters ::",characters)
print('Frequency of ',searchWord,'is ',count)

"""
content of b_div_data.txt
hi
i am learning python
we enjoying
we are from B division

Output:
Enter word to search: hi
lineno :: 4
words :: 12
characters :: 47
Frequency of  hi is  1

"""
