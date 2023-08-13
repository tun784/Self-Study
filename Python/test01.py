age = 19
name = "Tuan"
print(f"My name is {name} and I am {age}.")
print("My name is",name," and I am",age,".")
# age = int(input("Enter your age: "))
# print(f"Your age is: {age}")

# x=5
# y=9.65
# series='hello world !'
# bools = True
# z=complex(2,3)
# print(type(x))
# x=5.4
# print(type(x))
# print(type(y))
# print(type(series))
# print(type(bools))
# print(type(z))

year = 2020
nhuan = (year % 4 == 0 and year % 100 != 0) or (year % 400 == 0)
ketqua1 = 'nam nhuan' #năm nhuận
ketqua2 = 'nam khong nhuan' #năm không nhuận
if (nhuan):
    print(f"Nam {year} la {ketqua1}")
    print("-"*20)
else:
    print(f"Nam {year} la {ketqua2}")
    print('*'*10)
print(5 is 5)
print(9 is not 9)
print(9//2)
print(9/2)
print(9%2)