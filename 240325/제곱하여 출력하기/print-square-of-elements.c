#include <stdio.h>

int main() {
    // 여기에 코드를 작성해주세요.

    int n;
    unsigned int a, b, c;

    scanf("%d \n", &n);
    scanf("%d %d %d", &a, &b, &c);

    int arr[100] = {a, b, c};

    for(int i = 0; i < n; i++)
    {
        arr[i] *= arr[i];
    }

    for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}

    return 0;
}