#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void flushStdin() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void title() {
    int age;
    char name[100]; // Assuming a maximum name length of 100 characters
    printf("What's your name: ");
    scanf("%s", name);
    flushStdin();
    printf("What's your age: ");
    scanf("%d", &age);
    printf("Ban ten la %s va ban %d tuoi.\n", name, age);
}

void solve(float a, int b) {
    float sum = a + b;
    float minus = fabs(a - b);
    float multiply = a * b;
    float divide = (float) a / b;
    printf("%f\n", sum);
    printf("%f\n", minus);
    printf("%f\n", multiply);
    printf("%f\n", divide);
}

void condition(float a, int b) {
    if (a > b) {
        printf("%f lon hon %d\n", a, b);
        printf("Ket thuc chuong trinh.\n");
    } else if (a < b) {
        printf("%f be hon %d\n", a, b);
        printf("Ket thuc chuong trinh.\n");
    } else {
        printf("%f bang %d\n", a, b);
        printf("Ket thuc chuong trinh.\n");
    }
}

int main() {
    title();
    float a;
    float b;
    printf("Sau day la phan tinh toan, moi ban nhap so thuc bat ky: ");
    scanf("%f", &a);
    printf("Hay nhap them mot so thuc nua: ");
    scanf("%f", &b);
    solve(a, b);
    condition(a, b);
    system("pause");
    return 0;
}