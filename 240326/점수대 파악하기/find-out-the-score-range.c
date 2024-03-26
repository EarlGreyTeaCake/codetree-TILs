#include <stdio.h>

int main() {
    int n;
    int arr[100];

    int count_arr[100] = { 0, }; // 0번째는 비움

    while(1)
    {
        int i = 0;

        scanf("%d ", &arr[i]);

        if(arr[i] > 9) // 10 이상만
        {
            n = arr[i] / 10; // 십의 자리 얻기
            count_arr[n]++; // 같은 숫자 카운트
        }

        if(arr[i] == 0) // 0 나오면 끝
        {
            break;
        }

        i++;
    }

    // 개수 출력
	for (int i = 10; i > 0; i--) 
    {
		printf("%d - %d \n", i * 10, count_arr[i]);
	}

    return 0;
}