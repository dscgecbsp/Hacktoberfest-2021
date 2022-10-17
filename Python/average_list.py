
# Problem statement: Calculate the average of numbers in the list from user input. Program takes input from user until user enters 'done'. 

numlist = list()                        # create an empty list
while (True):
    inp = input('Enter a number: ')
    if inp == 'done': break             # exit loop and calculate avg when you enter'done'
    value = float(inp)
    numlist.append(value)               # append values in numlist

average = sum(numlist) / len(numlist)
print('Average:', average)
