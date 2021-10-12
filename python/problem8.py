# problem 8    interactive program


gender = input("Cat Gender?")
gender = gender.lower()
if gender == "male":
    print(" cat is male")
elif gender == "female":
    print("cat is female")
else:
    print("Invalid input")
age = int(input("Age of your cat? "))

if age < 5:
    print("cat age is", age)
else:
    print("Your cat is adult.")

x = 3
if x == 2:
    print('two')
elif x == 3:
    print('three')
elif x == 4:
    print('four')
else:
    print('something else')