import math

def title():
    age = int(input("What's your age: "))
    name = input("What's your name: ")
    print(f"Ban ten la {name} va ban {age} tuoi.")
    print("Ban ten la",name,"va ban",age,"tuoi.")

def solve(a, b):
    sum = a + b
    minus = abs(a - b)
    multiply = a * b
    divide = a / b
    print(sum)
    print(minus)
    print(multiply)
    print(divide)

def condition(a, b):
    if a > b:
        print(f"{a} lon hon {b}")
        print("Ket thuc chuong trinh.")
    elif a < b:
        print(f"{a} be hon {b}")
        print("Ket thuc chuong trinh.")
    else:
        print(a,"bang",b)
        print("Ket thuc chuong trinh.")

def main():
    title()
    a = int(input("Sau day la phan tinh toan, moi ban nhap mot so nguyen bat ky: "))
    b = int(input("Moi ban nhap mot so nguyen khac: "))
    solve(a, b)
    condition(a, b)

if __name__ == "__main__":
    main()