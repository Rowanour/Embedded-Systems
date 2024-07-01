// I Don't know why the headers were required to be included I didn't use them in the code!


#include <stdio.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"

// Define the enumerated data type for months
enum Month {
    JANUARY = 1,
    FEBRUARY,
    MARCH,
    APRIL,
    MAY,
    JUNE,
    JULY,
    AUGUST,
    SEPTEMBER,
    OCTOBER,
    NOVEMBER,
    DECEMBER
};

int main() {
    enum Month currentMonth = AUGUST;
    const char *monthNames[] = {
        "Invalid Month",
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };

    printf("Value of %s is %d\n", monthNames[currentMonth], currentMonth);

    return 0;
}

