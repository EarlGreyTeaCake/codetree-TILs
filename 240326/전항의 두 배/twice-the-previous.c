#include <stdio.h>

int main() {
    int n, m; // 첫번째항, 두번째항

    scanf("%d %d", &n, &m);

    int arr[10]; // 10번째 항까지 받는 array

    arr[0] = n, arr[1] = m; // 첫번째항, 두번째항 설정

    for(int i = 2; i < 10; i++)
    {
        arr[i] = arr[i - 1] + 2 * arr[i - 2]; // 점화식
    }

    for(int i = 0; i < 10; i++) // 전체 출력
    {
        printf("%d ", arr[i]);
    }

    return 0;
}