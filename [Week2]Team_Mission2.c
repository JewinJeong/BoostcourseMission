#include <stdio.h>

int main(){
    int money;
    printf("예금액 입력 : ");
    scanf("%d", &money);
    printf("만기시 금액 : %0.2f\n", money*1.012);
}
