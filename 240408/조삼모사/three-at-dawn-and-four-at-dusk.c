#include <stdio.h>
#include <stdlib.h>

#define MAXN 20 // 최대 업무의 수
#define INF 1000000000

void minimum_p_diff(int k, int morning_tasks[], int m, int afternoon_tasks[], int a);
int calc_p(int tasks[], int k);

int n; // 일의 양
int work_p[MAXN][MAXN]; // 업무 간의 상성 P_ij
int answer = INF; // 최소 상성을 저장할 변수

int main()
{
    scanf("%d\n", &n); // 일의 양 입력

    for(int i = 0; i < n; i++) // 업무 간의 상성 P_ij 입력
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d ", &work_p[i][j]);
        }
    }

    /*
     * 업무 상성을 나타내는 것이라 한 번에 같이 하게 되는 일의 숫자가 i와 j에 들어가게 되는듯
     * 아침에 하는 일과 저녁에 하는 일의 업무 강도 차이의 최솟값을 출력하는 것이 목표
     * 백트래킹
     * function 백트래킹(입력):
        if 입력이 해결책을 찾은 경우:
            결과 출력 또는 저장
            return

        for 각각의 가능한 선택지 in 입력에 대해:
            if 선택이 가능한 경우:
                선택
                백트래킹(새로운 입력) // 재귀 호출
                선택 취소 // 백트래킹
    */

    int morn_tasks[MAXN], after_tasks[MAXN]; // 아침에 하는 일, 저녁에 하는 일, 선택한 업무를 저장할 변수

    minimum_p_diff(0, morn_tasks, 0, after_tasks, 0);

    printf("%d\n", answer); // 최소 상성 차이 출력

    return 0;
}

// 백트래킹을 이용하여 최소 상성을 계산하는 함수
void minimum_p_diff(int k, int morning_tasks[], int m, int afternoon_tasks[], int a) // k는 업무의 수, morning_tasks는 아침에 하는 일, afternoon_tasks는 저녁에 하는 일, m은 아침에 하는 일의 수, a는 저녁에 하는 일의 수
{
    if(k == n) // 업무의 수가 n이거나 아침이나 저녁에 일하는 업무의 수가 n/2인 경우
    {
        int p_morning = calc_p(morning_tasks, m); // 아침의 업무 강도를 계산
        int p_afternoon = calc_p(afternoon_tasks, a); // 저녁의 업무 강도를 계산, 왜 n/2를 더하는지? -> n/2만큼 뒤로 이동해서 계산

        int diff = abs(p_morning - p_afternoon); // 아침과 저녁의 업무 강도 차이를 저장할 변수

        if(diff < answer) // 현재 상성이 최소 상성보다 작은 경우
        {
            answer = diff; // 최소 상성을 현재 상성으로 변경
        }

        return; // 최소 상성 반환
    }
    
    if(m < n/2) // 아침에 일하는 업무의 수가 n/2보다 작은 경우
    {
        morning_tasks[m] = k; // 아침에 일하는 업무에 현재 업무 추가
        minimum_p_diff(k + 1, morning_tasks, m + 1, afternoon_tasks, a); // 다음 업무로 이동
    }

    if(a < n/2) // 저녁에 일하는 업무의 수가 n/2보다 작은 경우
    {
        afternoon_tasks[a] = k; // 저녁에 일하는 업무에 현재 업무 추가
        minimum_p_diff(k + 1, morning_tasks, m, afternoon_tasks, a + 1); // 다음 업무로 이동
    }
}

int calc_p(int tasks[], int k) // 업무 간의 상성의 합(업무의 강도)을 구하는 함수
{
    int total_p = 0; // 업무 간의 상성의 합을 저장할 변수

    for(int i = 0; i < k; i++) // n/2만큼 반복 (n/2는 한 번에 같이 일하는 업무의 수)
    {
        for(int j = i + 1; j < k; j++) // n/2만큼 반복 (n/2는 한 번에 같이 일하는 업무의 수), i + 1한 이유는 같은 숫자는 업무 상성이 없으므로
        {
            total_p += work_p[tasks[i]][tasks[j]]; // 업무의 강도 계산
            total_p += work_p[tasks[j]][tasks[i]]; // 업무의 강도
        }
    }

    return total_p; // 업무 간의 상성의 합 (업무의 강도) 반환
}