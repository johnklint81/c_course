#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(void) {
  struct tm time1 = {0};
  struct tm time2 = {0};
  int *date1 = (int*)malloc(6 * sizeof(int));  //(int*) because malloc returns void*s
  int *date2 = (int*)malloc(6 * sizeof(int));
  int *date_difference = (int*)malloc(6 * sizeof(int));
  char **names = (char**)malloc(6 * sizeof(char*));
  names[0] = "years";
  names[1] = "months";
  names[2] = "days";
  names[3] = "hours";
  names[4] = "minutes";
  names[5] = "seconds";
  printf("Enter the first date (YYYY MM DD HH MM SS) with space separation: ");
  for (int i = 0; i < 6; ++i) {
    scanf("%d", &date1[i]);
  }
  printf("Enter the second date (YYYY MM DD HH MM SS) with space separation: ");
  for (int i = 0; i < 6; ++i) {
    scanf("%d", &date2[i]);
  }
  time1.tm_year = date1[0] - 1900;  // tm_year is years since 1900
  time1.tm_mon = date1[1] - 1;     // tm_mon is 0-based (0 = January, 1 = February, ...)
  time1.tm_mday = date1[2];          // tm_mday is the day of the month (1-31)
  time1.tm_hour = date1[3];
  time1.tm_min = date1[4];
  time1.tm_sec = date1[5];
  
  time_t timestamp1 = mktime(&time1);

  time2.tm_year = date2[0] - 1900;  
  time2.tm_mon = date2[1] - 1;     
  time2.tm_mday = date2[2];        
  time2.tm_hour = date2[3];
  time2.tm_min = date2[4];
  time2.tm_sec = date2[5];

  time_t timestamp2 = mktime(&time2);

  time_t secs = timestamp2 - timestamp1;
  printf("The difference in seconds is: %d\n", (int)secs);
  for (int i = 0; i < 6; ++i) {
    date_difference[i] = date2[i] - date1[i]; 
  }
  printf("The difference is: ");
  for (int i = 0; i < 6; ++i) {
    printf("%d %s ", date_difference[i], names[i]);

  }
  printf("\n");
  free(date1);
  free(date2);
}
