#include <stdio.h>

int main() {
    
    char arr_flag[3];
    int arr_temp[3];
    int a = 0, b = 0, c = 0, d = 0;
    
    for(int i = 0; i < 3; i++)
    {
        scanf("%c %d\n", &arr_flag[i], &arr_temp[i]);

        if(arr_flag[i] == 'Y' && arr_temp[i] > 37)
        {
            a++;
        }
        else if(arr_flag[i] != 'Y' && arr_temp[i] > 37)
        {
            b++;
        }
        else if(arr_flag[i] == 'Y' && arr_temp[i] < 37)
        {
            c++;
        }
        else
        {
            d++;
        }
    }

    printf("%d %d %d %d", a, b, c, d);

    if(a >= 2)
    {
        printf(" %c", 'E');
    }
    
    return 0;
}