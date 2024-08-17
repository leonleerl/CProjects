#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DEFAULT_MONTH 8
#define DEFAULT_YEAR 2024

#define N_WEEKS 6
#define N_DAYS_PER_WEEK 7

void print_cal(int month, int year)
{
    int days_in_month;
    switch (month)
    {
    case 1:
        days_in_month = 31;
        printf("   January %i\n", year);
        break;

    case 8:
        days_in_month = 31;
        printf("   August %i\n", year);

    default:
        break;
    }
    int day = 0;
    printf("Su Mo Tu We Th Fr Sa\n");
    for (int w = 0; w < N_WEEKS; w++)
    {
        for (int d = 0; d < N_DAYS_PER_WEEK; d++)
        {
            if (day >= 1 && day < days_in_month)
            {
                printf("%2i ", day);
            }
            else
            {
                printf(".. ");
            }

            day++;
        }
        printf("\n");
    }
}

int main(int argc, char *argv[])
{

    int month = DEFAULT_MONTH;
    int year = DEFAULT_YEAR;

    print_cal(month, year);

    exit(EXIT_SUCCESS);
    return EXIT_SUCCESS;
}
