#include <stdio.h>

int maximum_p(int date, int p);

int n; // 휴가 기간
int p_max; // 최대 수익
int t_arr[100], p_arr[100]; // 기한, 수익

int main() {

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

    p_max = maximum_p(0, 0);

    printf("%d", p_max);

    return 0;
}

int maximum_p(int date, int p)
{
    if(date > n)
    {
        return 0;
    }

    else if(date == n)
    {
        if(p > p_max)
        {
            return p;
        }

        else
        {
            return p_max;
        }
    }

    // 1일째 일 안하고 다음날로 건너뜀
    int p_skip = maximum_p(date + 1, p);

    // 1일째 일함
    int p_work = 0;

    if(date + t_arr[date] <= n) // 기한을 넘기지 않는 경우
    {
        p_work = maximum_p(date + t_arr[date], p + p_arr[date]);
    }


    if(p_skip > p_work)
    {
        return p_skip;
    }

    else
    {
        return p_work;
    }
}