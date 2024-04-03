#include <stdio.h>

int main() {
    
    char arr_flag[3]; // 증상 여부
    int arr_temp[3]; // 체온
    int a = 0, b = 0, c = 0, d = 0; // 진료소 A, B, C, D
    
    for(int i = 0; i < 3; i++)
    {
        scanf("%c %d\n", &arr_flag[i], &arr_temp[i]);

        if(arr_flag[i] == 'Y' && arr_temp[i] >= 37)
        {
            a++;
        }
        else if(arr_flag[i] != 'Y' && arr_temp[i] >= 37)
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

    if(a >= 2) // A 선별진료소로 가는 사람 2명 이상이면
    {
        printf(" %c", 'E'); // Emergency 프린트
    }
    
    return 0;
}