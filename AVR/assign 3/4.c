#include <stdio.h>
int main()
{
    int x ,y ,n ,z = 1;
    int array[10]={};
    printf("please enter your 10 numbers \n");
    //10 numbers from the user
    for (int i=0; i<=9;i++)
    {
        scanf("%d" ,&x);
        array[i]=x;
    }
    //a number to search for
    printf("please enter a number to search for ");
    scanf("%d" ,&y);
    //how many times the input number appears in the array
    for (int i=0; i<=9;i++)
    {
        if (y ==  array[i])
        {
            n = n + z;
        }
    }
    //result based on the count
    if(n ==0)
    {
        printf("value doesn't exist");
    }
    else
    {
        printf("%d exists %d times " ,y ,n);
    }
}