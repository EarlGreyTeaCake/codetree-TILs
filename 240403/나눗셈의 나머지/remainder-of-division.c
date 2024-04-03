#include <stdio.h>

int main() {
    
    int a, b;
    scanf("%d %d", &a, &b); // 두 정수 a, b

    int arr[100]; // 나머지
    int count_arr[100] = { 0, }; // 같은 나머지의 개수 카운트 (빈도 저장 배열)

    int i = 0;

    while(a > 1)
    {
        arr[i] = a % b; // 나머지 저장

        a /= b; // a를 b로 나누기

        count_arr[arr[i]]++; // 나머지 갯수 세기

        i++; // 배열의 크기를 자동으로 계산할 수 있도록
    }

    int res = 0;

    for(int j = 0; j < i; j++)
    {
        res += count_arr[j] * count_arr[j]; // 갯수를 제곱하여 더함
    }

    printf("%d", res);

    return 0;
}