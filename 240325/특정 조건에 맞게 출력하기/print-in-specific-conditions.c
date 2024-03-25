#include <stdio.h>

int main() {
    int arr[100];

    int i = 0;
    int n;

    while(1)
    {
        i = 0;

        scanf("%d ", &n);

        arr[i] = n;

        if(arr[i] == 0)
        {
            break;
        }

        if(arr[i] % 2 == 0)
        {
            printf("%d ", arr[i]/2);
        }
        else
        {
            printf("%d ", arr[i] + 3);
        }

        i++;
    }

    return 0;
}