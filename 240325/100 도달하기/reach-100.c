#include <stdio.h>

int main() {
    int n;

    scanf("%d", &n);

    int arr[100];

    arr[0] = 1;
    arr[1] = n;

    printf("%d %d ", arr[0], arr[1]);

    int i = 2;

    while(1)
    {
        arr[i] = arr[i - 1] + arr[i - 2];

        printf("%d ", arr[i]);

        if(arr[i] > 100)
        {
            break;
        }

        i++;
    }

    return 0;
}