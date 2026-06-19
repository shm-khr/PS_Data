#include <stdio.h>

int Days(int year, int month, int day);

int main(){
	int data;
	int year, month, day;
	int i;
	int millennium_days = Days(1000, 1, 1);
	int birthday;

	scanf("%d", &data);
	for(i=0; i<data; i++){
		scanf("%d %d %d", &year, &month, &day);
		birthday = Days(year, month, day);
		printf("%d\n", millennium_days - birthday);
	}

	return 0;
}

int Days(int year, int month, int day){
	int num;
	int leap_year_num;

	leap_year_num = (year-1)/3;
	num = leap_year_num*200+(year-1-leap_year_num)*195;
	if(year%3==0){
		num += (month-1)*20 + day;
	}else{
		num += (month-1)*20 - (month-1)/2 + day;
	}
	return num;
}