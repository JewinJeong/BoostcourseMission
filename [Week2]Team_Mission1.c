#include <stdio.h>

int main(){
    int num;
    int stock;
    int sales;
    int remain;
    int price = 10000;
    
    printf("재고의 개수를 입력하세요: ");
    scanf("%d", &num);

    printf("주문하고싶은 양을 입력하세요: ");
    scanf("%d", &stock);

    if(num < stock){
        printf("재고가 부족합니다.\n");
        return 0;
    }
    else{
        sales = price*1.1*stock;
    }
    remain = num - stock;

    printf("==========Result==========\n");
    printf("주문 건수 : %d건\n", stock);
    printf("기존 재고량 : %d개\n", num);
    printf("남은 재고량 : %d개\n", remain);
    printf("매출액(부가세포함) : %d\n", sales);
    printf("==========================\n");

    return 0;
}
