#include <iostream>
using namespace std;
void flushStdin() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
void title(){
    int age;
    string name;
    cout << "What's your name: ";
    cin >> name;
    flushStdin();
    cout << "What's your age: ";
    cin >> age;
    cout << "Ban ten la " << name << " va ban " << age << " tuoi.\n";
}
void solve(float a, int b){
    float sum = a + b;
    float minus = abs(a - b);
    float multiply = a * b;
    float divide = (float) a / b;
    cout << sum << endl;
    cout << minus << endl;
    cout << multiply << endl;
    cout << divide << endl;
}
void condition(float a, int b){
    if (a > b){
        cout << a << " lon hon " << b << endl;
        cout << "Ket thuc chuong trinh." << '\n';
    }
    else if (a < b){
        cout << a << " be hon " << b << endl;
        cout << "Ket thuc chuong trinh." << '\n';
    }
    else {
        cout << a << " bang " << b << endl;
        cout << "Ket thuc chuong trinh." << '\n';
    }
}
int main(){
    title();
    float a;
    float b;
    cout << "Sau day la phan tinh toan, moi ban nhap so thuc bat ky: ";
    cin >> a;
    cout << "Hay nhap them mot so thuc nua: ";
    cin >> b;
    solve(a,b);
    condition(a,b);
    system("pause");
    return 0;
}