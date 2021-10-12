# problem 10 - functions without  parameters

def currentYear():
    print('2018')
currentYear()    


def f(x,y):     # with parameters
    return x*y


print(f(3,4))
result = f(3,4)   # return to a variable 
print(result)
print('\n')  


num = [1,2,3,4,5,6,7,8,9]
print('x^2 loop:')
for x in num:
    y = x * x
    print(str(x) + '*' + str(x) + '=' + str(y))

# Python lists
pythonList = [ "New York", "Los Angles", "Boston", "Denver" ]

print(pythonList)     # prints all elements
print(pythonList[0])  # print first element
print(pythonList[-1]) # print last element
