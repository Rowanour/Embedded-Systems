#include <stdio.h>
struct distance
{
    int feet;
    int inch;
}d1,d2;

main()
{
    printf("please enter distance 1 in feet ");
    scanf("%d" ,&d1.feet);
    printf("please enter distance 1 in inch ");
    scanf("%d" ,&d1.inch);

    printf("please enter distance 2 in feet ");
    scanf("%d" ,&d2.feet);
    printf("please enter distance 2 in inch ");
    scanf("%d" ,&d2.inch);

    int resultf=0 , resulti=0;
    resultf += d1.feet +d2.feet;
    resulti += d1.inch +d2.inch;

    while (resulti>12)
    {
        resultf ++;
        resulti -= 12;
    }

    printf("sum = \n %d feet and %d inches", resultf,resulti );
    return 0;
}
