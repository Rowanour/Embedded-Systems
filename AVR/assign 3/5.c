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
    //number to search for
    printf("please enter a number to search for ");
    scanf("%d" ,&y);
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

     // Binary Search
    int left, right = 9, mid, found =0;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (array[mid] == y) {
            found = 1;
            break;
        } else if (array[mid] < y) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    //search result
    if (found) {
        printf("\nValue found\n");
    } else {
        printf("\nValue not found\n");
    }

    return 0;
}

