#include <stdio.h>

int main() {
    int n;
    unsigned int k;

    scanf("%d \n", &n); // 우선 배열의 크기가 될 값 n 받기

    int arr[100]; // 배열 선언

    for(int i = 0; i < n; i++) // scanf로 입력받을 크기만큼의 입력받기
    {
        scanf("%d ", &k);
        arr[i] = k;
    }

    for(int i = 0; i < n; i++) // 제곱
    {
        arr[i] *= arr[i];
    }

    for (int i = 0; i < n; i++) // 프린트
    {
		printf("%d ", arr[i]);
	}

    return 0;
}