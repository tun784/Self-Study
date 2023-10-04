def UCLN(a,b):
    while b:
        a, b = b, a % b
    return a

def BCNN(a,b):
    return (a*b) // UCLN(a,b)

def main():
    try:
        # Nhập hai số nguyên
        num1 = int(input("Nhap so nguyen thu nhat: "))
        num2 = int(input("Nhap so nguyen thu hai: "))
        
        # Tìm ước chung lớn nhất
        ucln = UCLN(num1, num2)
        print("Uoc chung lon nhat cua",num1,"va",num2,"la",ucln)
        # Tìm bội chung nhỏ nhất
        bcnn = BCNN(num1, num2)
        print("Boi chung nho nhat cua",num1,"va",num2,"la",bcnn)
        
    except ValueError:
        print("Vui long nhap so nguyen hop le.")
        
if __name__ == "__main__":
    main()