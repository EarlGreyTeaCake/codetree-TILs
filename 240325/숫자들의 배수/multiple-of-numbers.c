#include <stdio.h>

int main() {
    int n;
    int flag = 0;

    scanf("%d", &n);

    int arr[100];

    arr[0] = n;

    for(int i = 0; i <= 10; i++)
    {
        arr[i] = n * (i + 1); // 배수

        printf("%d ", arr[i]);

        if(arr[i] % 5 == 0)
        {
            flag++;

            if(flag > 1)
            {
                break;
            }
        }
    }

    return 0;
}