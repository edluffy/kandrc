#include <stdio.h>


int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);

/* add error checking */
int main(void)
{
	int day, month, year, yearday;

	printf("Enter: 'day, month, year'\n");

	scanf("%i, %i, %i", &day, &month, &year);
	printf("Day of the year: %i\n", day_of_year(year, month, day));


	printf("Enter: 'year, day of year'\n");
	scanf("%i, %i", &year, &yearday);

	month_day(year, yearday, &month, &day);
	printf("Day: %i, Month: %i", day, month);
}

static char daytab[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int day)
{
	int i, leap;
	leap = year%4 == 0 && year%100 != 0 || year%400 == 0;

	// error checking
	if(day > daytab[leap][month] || month > 12){
		printf("error: invalid day or month\n");
		return -1;
	}

	for(i = 1; i < month; i++)
		day += daytab[leap][i];
	return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday)
{
	int i, leap;
	leap = year%4 == 0 && year%100 != 0 || year %400 == 0;
	
	// error checking
	if(yearday > ((leap) ? 366 : 365)){
		printf("error: invalid day\n");
		return;
	}	
	for(i = 1; yearday > daytab[leap][i]; i++)
		yearday -= daytab[leap][i];
	*pmonth = i;
	*pday = yearday;
}
