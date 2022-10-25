// 다음과 같이 include를 사용할 수 있습니다.
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
bool ch(int **garden, int garden_row_len, int garden_col_len){
        for(int i=0; i < garden_row_len; i++){
           for(int j=0; j < garden_col_len; j++){
               // printf("%d ",garden[i][j]);
                if(garden[i][j]==0) return false;
           }
           printf("\n");
        }
    return true;
}
int solution(int **garden, int garden_row_len, int garden_col_len) {
    // 여기에 코드를 작성해주세요.
    int answer = 0;
  while(true){
     if(ch(garden,garden_row_len,garden_col_len)) break;
       int **temp= (int **)malloc(sizeof(int*) * garden_row_len);
       for(int i=0; i < garden_row_len; i++){
        temp[i] = (int *)malloc(sizeof(int *) * garden_col_len);
       }
               for(int i=0; i < garden_row_len; i++){
           for(int j=0; j < garden_col_len; j++){
                    temp[i][j] = garden[i][j];
           }
        }
       for(int i=0; i < garden_row_len; i++){
           for(int j=0; j < garden_col_len; j++){
               if(garden[i][j] == 1){
                   for(int k=0; k < 4; k++){
                       int x = i + dx[k]; // row
                       int y = j + dy[k]; // col
                       if(x >= 0 && x < garden_row_len && y >= 0 && y < garden_col_len){
                           temp[x][y] = 1;
                           printf("%d\n",garden[x][y]);
                       }
                   }
               }
           }
       }
        for(int i=0; i < garden_row_len; i++){
           for(int j=0; j < garden_col_len; j++){
                printf("%d ",temp[i][j]);
           }
           printf("\n");
        }
        garden = temp;
        answer++;
   }
    return answer;
}


// 아래는 테스트케이스 출력을 해보기 위한 main 함수입니다.
int main() {
    int garden1_row_len = 3;
    int garden1_col_len = 3;
    int **garden1 = (int**)malloc(sizeof(int*) * garden1_row_len);
    for(int i = 0; i < garden1_row_len; i++)
        garden1[i] = (int*)malloc(sizeof(int) * garden1_col_len);

    garden1[0][0] = 0;
    garden1[0][1] = 0;
    garden1[0][2] = 0;
    garden1[1][0] = 0;
    garden1[1][1] = 1;
    garden1[1][2] = 0;
    garden1[2][0] = 0;
    garden1[2][1] = 0;
    garden1[2][2] = 0;

    int ret1 = solution(garden1, garden1_row_len, garden1_col_len);

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    printf("solution 함수의 반환 값은 %d 입니다.\n", ret1);

    int garden2_row_len = 2;
    int garden2_col_len = 2;
    int **garden2 = (int**)malloc(sizeof(int*) * garden2_row_len);
    for(int i = 0; i < garden2_row_len; i++)
        garden2[i] = (int*)malloc(sizeof(int) * garden2_col_len);

    garden2[0][0] = 1;
    garden2[0][1] = 1;
    garden2[1][0] = 1;
    garden2[1][1] = 1;

    int ret2 = solution(garden2, garden2_row_len, garden2_col_len);

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    printf("solution 함수의 반환 값은 %d 입니다.\n", ret2);
}