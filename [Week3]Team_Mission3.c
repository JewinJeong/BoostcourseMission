#include <stdio.h>
#define MAXQSIZE 10
int queue[MAXQSIZE];

void Enqueue(int* back, int item){
    if(*back == MAXQSIZE - 1){
        printf("큐가 가득참\n");
        return;
    }
    queue[++*back] = item;
}
void Dequeue(int* front, int back){
    if(*front == back){
        printf("큐가 비었음\n");
        return;
    }
    printf("%d", queue[++*front]);
}
void Display(int front, int back){
    if(front == back){
        printf("큐가 비었음\n");
        return;
    }
    for(int i = front; i< back; ){
        printf("%d\n", queue[++i]);
    }
}

int main(){
    int input, item;
    int front = -1;
    int back = -1;
    while(1){
        printf("1. 삽입\n");
        printf("2. 삭제\n");
        printf("3. 조회\n");
        printf("4. 종료\n");
        printf("입력 : ");
        scanf("%d", &input);
    
        switch(input){
        case 1:
            printf("삽입할 값 : ");
            scanf("%d", &item);
            Enqueue(&back, item);
            break;
        case 2:
            Dequeue(&front, back);       
            // printf("%d\n", Dequeue(&front, back));
            break;
        case 3:
            Display(front, back);
            break;
        case 4:
            return 0;
        }    
    }
}
