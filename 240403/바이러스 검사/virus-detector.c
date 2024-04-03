#include <stdio.h>

int main() {

    /*
    답의 범위가 10^12까지 커질 수 있는 문제입니다. 
    C/C++/Java에서의 int형의 경우 2^31−1 까지만 값 표현이 가능하므로 언어별로 다른 자료형을 사용하셔야 합니다.
    */
    
    long long rest; // 식당 갯수

    scanf("%lld", &rest); // 식당 갯수 받아옴


    long long cust[10000000]; // 각 식당의 고객 수

    for(long long i = 0; i < rest; i++) // 식당 갯수만큼
    {
        scanf("%lld ", &cust[i]); // 받아옴
    }


    long long max_ldr, max_mbr; // 팀장 또는 팀원 1명이 검사 가능한 최대 고객의 수

    scanf("%lld %lld ", &max_ldr, &max_mbr);


    /*
    우선 팀장이 검사할 수 있는 인원을 빼고, 남은 인원을 팀원이 검사할 수 있는 인원으로 나누고 그 몫에 +1해보자
    */

    long long result = 0;
    long long temp[10000000];

    for(long long i = 0; i < rest; i++) // 식당 갯수만큼
    {
        if(cust[i] > max_ldr) // 팀장이 맡을 수 있는 수보다 손님이 더 많다면
        {
            temp[i] = (cust[i] - max_ldr) / max_mbr; // 팀원이 검사할 전체 인원을, 팀원 1명이 검사 가능한 인원으로 나눔

            temp[i] = temp[i] + 1; // 팀장 1명 더해줌

            long long remain = (cust[i] - max_ldr) % max_mbr; // 나누고 남은 나머지 인원

            if(remain > 0 && remain < max_mbr) // 나머지가 0명이 아니고, 최대 검사 가능 인원보다 적다면?
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

    printf("%lld", result); // 출력

    return 0;
}