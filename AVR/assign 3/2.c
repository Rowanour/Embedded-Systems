#include <stdio.h>
int main()
{
    int x;
    int array[5] ={8,5,7,6,3};
    printf("please enter a number ");
    scanf("%d" ,&x);
    //loop through the array to find the index of the entered number
    for (int i=0 ; i<=4; i++)
    {
        // Check if the current array element is equal to the entered number
        if (array[i]==x )
        {
            // uf a match is found, print the index and exit the program
            printf("the index is %d" ,i);
            return 0;
        }
    }
    // if the entered number is not found in the array, print -1
    printf("-1");
}