#include <stdio.h>

int main() {
    int n; // 배열 크기
    int k;

    scanf("%d \n", &n); // 우선 배열의 크기가 될 값 n 받기

    int arr[100]; // 최대크기 100
    int count_arr[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }; // 0번은 더미

    // scanf로 입력받을 크기만큼의 입력받기
	for (int i = 0; i < n; i++) 
    {
		scanf("%d ", &k);
        arr[i] = k;
	}

	// 입력받은 크기만큼의 범위에서 개수 세기
	for (int i = 0; i < n; i++) 
    {
		count_arr[arr[i]]++;
	}

	// 개수 출력
	for (int i = 1; i < 10; i++) 
    {
		printf("%d \n", count_arr[i]);
	}

	return 0;
}