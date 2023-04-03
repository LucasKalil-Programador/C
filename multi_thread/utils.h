#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* seconds_time_str(int seconds) {
  int hours = seconds / 3600;
  seconds = seconds % 3600;
  int minutes = seconds / 60;
  seconds = seconds % 60;

  char* buffer = malloc(32);
  int len = snprintf(buffer, 100, "%02d:%02d:%02d", hours, minutes, seconds) + 1;

  char* str = malloc(len);
  memcpy(str, buffer, len);
  free(buffer);

  return str;
}