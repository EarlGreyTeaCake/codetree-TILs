#include <stdio.h>
#include <stdlib.h>

int minimum_p_diff(int k, int tasks[], int start);
int calc_p(int tasks[], int k);

int answer = 1000000000; // 최소 상성을 저장할 변수

int n; // 일의 양
int work_p[100][100]; // 업무 간의 상성 P_ij

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

    int tasks[100]; // 업무를 저장할 배열 (업무의 수만큼) -> 업무의 순서를 저장하는 배열

    printf("%d\n", minimum_p_diff(0, tasks, 0)); // 최소 상성 차이 출력

    return 0;
}

int minimum_p_diff(int k, int tasks[], int start) // 백트래킹을 이용하여 최소 상성을 계산하는 함수
{
    int p_morning, p_afternoon; // 아침과 저녁의 업무 강도를 저장할 변수

    if(k == n) // 업무의 수만큼 업무를 선택한 경우
    {
        p_morning = calc_p(tasks, n/2); // 아침의 업무 강도를 계산
        p_afternoon = calc_p(tasks + n/2, n/2); // 저녁의 업무 강도를 계산, 왜 n/2를 더하는지? -> n/2만큼 뒤로 이동해서 계산

        int diff = abs(p_morning - p_afternoon); // 아침과 저녁의 업무 강도 차이를 저장할 변수

        if(diff < answer) // 현재 상성이 최소 상성보다 작은 경우
        {
            answer = diff; // 최소 상성을 현재 상성으로 변경
        }

        return answer; // 최소 상성 반환
    }

    for(int i = start; i < n; i++) // 업무의 수만큼 반복
    {
        tasks[k] = i; // 업무 저장
        minimum_p_diff(k + 1, tasks, i + 1); // 백트래킹을 이용하여 최소 상성을 계산하는 함수 호출
        tasks[k] = 0; // 업무 초기화
    }

    return answer; // 아침과 저녁의 업무 강도의 최소 차이를 반환
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