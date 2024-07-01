#include <stdio.h>
int main()
{
int arr[5] = {2,10,5,8,3};
int *ptr;
ptr =arr;
int x = 0;
printf("enter a number to search for ");
scanf("%d" ,&x);
for (int i=0; i<5; i++)
{
    if (x == ptr[i])
    {
        printf("element found");
        return 0;
    }
    
}
printf("element NOT found");

}