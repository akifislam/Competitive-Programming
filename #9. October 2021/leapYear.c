#include <stdio.h>

int IsLeapYear(int year)
{
    return (((year % 4 == 0) &&
             (year % 100 != 0)) ||
            (year % 400 == 0));
}

int main()
{
    int isValid = 1;
    int year, month, day;

    scanf("%d/%d/%d", &year, &month, &day);

    if (year < 2000 || year >= 2100)
    {
        printf("Invalid Year\n");
        isValid = 0;
    }

    if (month < 1 || month > 12)
    {
        printf("Invalid Month\n");
        isValid = 0;
    }

    if (month == 2 && IsLeapYear(year))
    {
        if (day < 1 || day > 29)
        {
            printf("Invalid Day\n");
            isValid = 0;
        }
    }
    else if (month == 2)
    {
        if (day < 1 || day > 28)
        {
            printf("Invalid Day\n");
            isValid = 0;
        }
    }
    else if (month == 9 || month == 4 || month == 6 || month == 11)
    {
        if (day < 1 || day > 30)
        {
            printf("Invalid Day\n");
            isValid = 0;
        }
    }
    else
    {
        if (day < 1 || day > 31)
        {
            printf("Invalid Day\n");
            isValid = 0;
        }
    }

    if (isValid == 1)
        printf("Valid\n");
}