#include <stdio.h>
int main()
{
    int n = 10;
    int a[] = {3,2,6,5,4,7,8,9,5,1};
    int min_index;
    for(int i = 0; i < n - 1; i++) {
        min_index = i;
        for(int j = i + 1; j < n; j++) {
            if(a[min_index] > a[j]) {
                min_index = j;
            }
        }
        if(min_index != i)
        {
            int temp = a[i];
            a[i] = a[min_index];
            a[min_index] = temp;
        }
    }
    printf("Sorted Array: ");
    for(int i = 0; i < n; i++)  {
        printf(" %d", a[i]);
    }
    return 0;
}
