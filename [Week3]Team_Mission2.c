#include <stdio.h>
#include <stdlib.h>

//1부터 n까지의 합
int sum_all(int n){
    int sum = 0;
    for(int i = 1; i< n+1; i++){
        sum += i;
    }
    return sum;
}

int main(int argc, char** argv){
    FILE *fin;
    int tmp;
    int i = 0;
    int first;
    int sum = 0;
    if (argc == 2){// 입력 값이 들어오는지 확인
        fin = fopen(argv[1], "r");
        if (!fin){// 파일이 열리는지 확인
            printf("파일오픈 실패\n");
            exit(1);
        }
        while(!feof(fin)){
            if(i == 0){//첫 번째 줄 문자 확인
                fscanf(fin, "%d", &first);
                i++;
            }
            else{
                fscanf(fin, "%d", &tmp);// 나머지 숫자 다 더하기 
                sum += tmp;
            }
        }
        printf("%d\n", sum_all(first) - sum);//빠진 숫자 계산
    }
    else{
        printf("비정상입력\n");
        exit(1);
    }
}
