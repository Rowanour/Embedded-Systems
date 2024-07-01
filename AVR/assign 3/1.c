#include <stdio.h>
int main()
{
    int x;
    int array[10]={};
    //take numbers from the user
    for (int i=0; i<=9;i++)
    {
        scanf("%d" ,&x);
        array[i]=x;
    }
    //print in reverse
    for (int i=0; i<=9;i++)
    {
    printf("%d" ,array[9-i]);
    }
}