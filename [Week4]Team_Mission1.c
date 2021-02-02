#include <stdio.h>

void quick_sort(int *data, int start, int end){
    //data가 하나 있을 경우
    if(start >= end){
        return;
    }
    int pivot = start;
    int i = pivot+1;//pivot다음 출발
    int j = end;//오른쪽 끝 출발지점
    int temp;

    while(i <= j){
        // i는 pivot 보다 커야함
        while(i <= end && data[i] <= data[pivot]){
            i++;
        }
        while(j > start && data[j] >= data[pivot]){
            j--;
        }
        if(i > j){
            temp = data[j];
            data[j] = data[pivot];
            data[pivot] = temp;
        }else{
            temp = data[i];
            data[i] = data[j];
            data[j] = temp;
        }
    }
    quick_sort(data, start, j - 1);
    quick_sort(data, j+1, end);
}
int compare(int a[], int b[]){
    for(int i = 0; i < 5; i++){
        if(a[i] == b[i]){
            continue;
        }
        else{
            return 0;
        }
    }
    return 1;
}
int main(void){
    int a[5], b[5];
    printf("입력값 : ");
    //값 배열로 입력받기
    for(int i = 0; i<5; i++){
        scanf("%1d", &a[i]);
    }
    for(int i = 0; i<5; i++){
        scanf("%1d", &b[i]);
    }
    
    //a,b 퀵소트 이용해서 정렬
    quick_sort(a, 0, 4);
    quick_sort(b, 0, 4);

    //비교하여 같으면 1 다르면 0출력
    if(compare(a, b) == 1){
        printf("True\n");
    }else{
        printf("False\n");
    }
}
