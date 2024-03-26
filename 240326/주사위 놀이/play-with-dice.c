#include <stdio.h>

int main() {
    int n = 10; // 배열 크기
    const int count = 7; // 카운트 배열의 크기, 0번은 더미

    int arr[n]; // 배열의 최대크기 100
    int count_arr[7] = { 0, }; // 0번은 더미

    // scanf로 입력받을 크기만큼의 입력받기
	for (int i = 0; i < n; i++) 
    {
		scanf("%d ", &arr[i]);
	}

	// 입력받은 크기만큼의 범위에서 개수 세기
	for (int i = 0; i < n; i++) 
    {
		count_arr[arr[i]]++;
	}

	// 개수 출력
	for (int i = 1; i < count; i++) 
    {
		printf("%d - %d \n", i, count_arr[i]);
	}

	return 0;
}