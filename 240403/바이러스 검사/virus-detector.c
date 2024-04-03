#include <stdio.h>

int main() {
    
    int rest; // 식당 갯수

    scanf("%d", &rest); // 식당 갯수 받아옴


    int cust[100]; // 각 식당의 고객 수

    for(int i = 0; i < rest; i++) // 식당 갯수만큼
    {
        scanf("%d ", &cust[i]); // 받아옴
    }


    int max_ldr, max_mbr; // 팀장 또는 팀원 1명이 검사 가능한 최대 고객의 수

    scanf("%d %d", &max_ldr, &max_mbr);


    /*
    우선 팀장이 검사할 수 있는 인원을 빼고, 남은 인원을 팀원이 검사할 수 있는 인원으로 나누고 그 몫에 +1해보자
    */

    int result = 0;
    int temp[100];

    for(int i = 0; i < rest; i++) // 식당 갯수만큼
    {
        if(cust[i] > max_ldr) // 팀장이 맡을 수 있는 수보다 손님이 더 많다면
        {
            temp[i] = ((cust[i] - max_ldr) / max_mbr); // 팀원이 검사할 전체 인원을, 팀원 1명이 검사 가능한 인원으로 나눔

            temp[i] = temp[i] + 1; // 팀장 1명 더해줌

            int remain = (cust[i] - max_ldr) % max_mbr;

            if(remain != 0 && remain < max_mbr) // 나머지가 0명이 아니고, 최대 검사 가능 인원보다 적다면?
            {
                temp[i] = temp[i] + 1; // 팀원 1명 더 추가
            }
        }

        else if(cust[i] <= max_ldr) // 팀장이 맡을 수 있는 수보다 손님이 같거나 더 적다면
        {
            temp[i] = 1; // 팀장만 있으면 됨
        }

        result += temp[i]; // 결과를 더해줌
    }

    printf("%d", result); // 출력

    return 0;
}