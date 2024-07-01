#include <stdio.h>
int sumofdigit(int num);
int main()
{
    int num;
    printf("enter a number ");
    //input number
    scanf("%d" ,&num);
    int result = sumofdigit(num);
    printf("the sum of digits is %d" ,result);

}
//function to add digits og the number
int sumofdigit (num)
{
    int sum;
    while(num>0)
    {
        int remainder = num%10;
        sum = sum + remainder;
        num = num /10;
    }
    return sum;
}