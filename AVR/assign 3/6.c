#include <stdio.h>
int main()
{
    int x ,y, z=1;
    int array[10]={};
    //10 numbers from the user
    printf("please enter your 10 numbers \n");
    for (int i=0; i<=9;i++)
    {
        scanf("%d" ,&x);
        array[i]=x;
    }
    
    //sort the array in ascending order
    for (int j = 0 ; j<=8; j++)
    {
        for(int i = 0; i<=8; i++)
        {
            if (array[i] > array[i+1])
            {
                z = array[i];
                array[i] = array[i+1];
                array[i+1] = z;
            }
        }
    }
    //print sorted array
    for (int i=0; i<=9;i++)
    {
    printf("%d" ,array[i]);
    }
}