#include <stdio.h>

int maximum_p(int date, int p);

int n; // 휴가 기간

int t_arr[100], p_arr[100]; // 기한, 수익

int main() {

    int p_max; // 최대 수익

    scanf("%d", &n);

    for(int i = 0; i < n + 1; i++)
    {
        scanf("%d %d", &t_arr[i], &p_arr[i]);
    }

    /* 문제 접근을 어떻게 할까?
     * 휴가 기간 이후부터는 각 일자 순서로 외주 조건이 적혀있음
     * 기한을 넘기지 않도록 해야함
     * 일을 했을 때와 하지 않았을 때의 분기점으로 나누는 것이 포인트
    */

    p_max = maximum_p(0, 0); // 초기상태부터 시작 (0일째 일함, 수익 0)

    printf("%d", p_max); // 최대 수익 출력

    return 0;
}

// 함수 요약: date일째 일을 했을 때의 최대 수익을 반환하는 함수 (재귀)
int maximum_p(int date, int p)
{
    if(date > n) 
    {
        return 0;
    }

    else if(date == n) 
    {
        return p;
    }

    
    int p_skip = maximum_p(date + 1, p); // 일을 하지 않았으니 다음날로 날짜만 업데이트

    // 1일째 일함
    int p_work = 0; // 일을 했을 때의 수익

    if(date + t_arr[date] <= n) // 기한을 넘기지 않는 경우
    {
        p_work = maximum_p(date + t_arr[date], p + p_arr[date]); // 일을 한 경우의 경과한 날짜와 수익 업데이트
    }


    if(p_skip > p_work) // 일을 하지 않았을 때의 수익이 더 큰 경우
    {
        return p_skip;
    }

    else // 일을 했을 때의 수익이 더 큰 경우
    {
        return p_work;
    }
}