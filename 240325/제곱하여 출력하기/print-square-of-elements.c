#include <stdio.h>

int main() {
    int n;
    unsigned int k;

    scanf("%d \n", &n);

    int arr[100];

    for(int i = 0; i < n; i++)
    {
        scanf("%d ", &k);
        arr[i] = k;
    }

    for(int i = 0; i < n; i++)
    {
        arr[i] *= arr[i];
    }

    for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}

    return 0;
}