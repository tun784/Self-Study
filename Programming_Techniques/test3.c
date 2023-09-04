#include <stdio.h>

int main(){
    int number1, number2, number3, number4;
    printf("Nhap cac so nguyen bat ky: ");
    int i = scanf("%d%d%d%d", &number1, &number2, &number3, &number4);
    printf("Lenh scanf: %d\n",i);
    return 0;
}