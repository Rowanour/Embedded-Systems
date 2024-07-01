#include <stdio.h>
int main()
{
int arr[5] = {2,10,5,8,3};
int *ptr;
ptr =arr;
int arr2[5];

for (int i=0; i<5; i++)
{
    arr2[i] = ptr[4-i];
}
for (int i=0; i<5; i++)
{
    printf("%d \n", arr2[i]);
}

}