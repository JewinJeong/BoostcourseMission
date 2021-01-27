#include <stdio.h>
#include <cs50.h>
#include <string.h>

const int NUMBER_OF_GRADES = 9;
const int SCORES[NUMBER_OF_GRADES] = {95, 90, 85, 80, 75, 70, 65, 60, 0};
const string GRADES[NUMBER_OF_GRADES] = {"A+", "A", "B+", "B", "C+", "C", "D+", "D", "F"};

int main(){
    printf("학점 프로그램\n");
    printf("종료를 원하면 \"999\"를 입력\n");
    printf("[학점 테이블]\n");
    printf("점수 : 95\t 90\t 85\t 80\t 75\t 70\t 65\t 60\t 0\n");
    printf("학점 : A+\t A \t B+\t B \t C+\t C \t D+\t D \t F\n");

    while(1){
        int score;
        printf("성적을 입력하세요 (0 ~ 100) : ");
        scanf("%d", &score);
        if(score == 999){
            printf("종료합니다.\n");
            break;
        }
        else if(score <= 100 && score >= 0){
            for(int i = 0; i < 10; i++){
                if(score >= SCORES[i]){
                    printf("%s\n", GRADES[i]);
                    break;
                }
            }
        }
        else{
            printf("잘못입력하셨습니다. 다시 입력하세요\n");
        }
    }
}
