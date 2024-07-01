#include <stdio.h>
struct time
{
    int sec;
    int min;
    int hours;
}t1,t2;

int main()
{
    printf("please enter your start time in \nhours \nminutes \nseconds\n");
    scanf("%d %d %d" ,&t1.hours ,&t1.min ,&t1.sec);
    printf("please enter your stop time in \nhours \nminutes \nseconds\n");
    scanf("%d %d %d" ,&t2.hours ,&t2.min ,&t2.sec);

    int time_diff = 0;

    int diffsec = 0; int diffmin = 0; int diffhours = 0;
    if (t1.sec<t2.sec)
    {
        diffsec = t2.sec - t1.sec;
    }
    else
    {
        diffmin --;
        diffsec = 60 - (t1.sec - t2.sec);
    }

    if (t1.min<t2.min)
    {
        diffmin = t2.min - t1.min;
    }
    else
    {
        diffhours --;
        diffmin = 60 - (t1.min - t2.min);
    }

    diffhours = t2.hours - t1.hours;
    
    printf("time difference is \n%d hours \n%d minutes \n%d seconds", diffhours, diffmin, diffsec);

}
