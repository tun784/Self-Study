#include <iostream>
#pragma warning (disable: 4996)

int main() {
    int number_a, number_b;
    std::cout << "Nhap hai so nguyen bat ky: ";

    if (!(std::cin >> number_a >> number_b)) {
        std::cout << "Nhap khong hop le." << std::endl;
        return 1;
    }
    
    try {
        if (number_b != 0) {
            float ketqua = (float) number_a / number_b;
            std::cout << "Ket qua cua " << number_a << "/" << number_b << " = " << ketqua << std::endl;
        }
        else
            //throw(number_b);
            
            throw "Ban da nhap so chia la mot so khong chia duoc.";

            //throw 500;
    }

    // catch (int num){
    //     std::cout << "Ban khong duoc nhap so " << num << std::endl;
    // }

    catch (const char *error){
        std::cout << "Loi: " << error << std::endl;
    }

    // catch (int Error){
    //     std::cout << "Loi: " << Error << std::endl; 
    // }
    return 0;
}