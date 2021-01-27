#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(){
    //무슨 요일인지 입력 받기
    string s1;
    scanf("%s", s1);
    //요일별 음식 string 2차원 배열 선언
    string str[7][2] = {{"월요일", "청국장"},{"화요일", "비빔밥"}, {"수요일", "된장찌개"}, {"목요일", "칼국수"},{"금요일","냉면"},{"토요일","소불고기"},{"일요일","오삼불고기"}};
    
    for(int i = 0; i < 7; i++){
        //입력받은 요일과 배열에 있는 요일 비교해서 해당 index 배열 출력
        if(strcmp(str[i][0], s1) == 0){ //strcmp는 두 string을 비교해 같으면 0 출력
            printf("%s : %s\n", str[i][0], str[i][1]);
            break;
        }
        else{//요일이 잘못 입력되면 for문 중지
            printf("안먹어요\n");
            break;
        }
    }
}
