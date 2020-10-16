#include <stdio.h>
#include <math.h>
int main(){
  float hour, minute;
  char colon;
  printf("What time is it? ");
  scanf("%f%c%f", &hour, &colon, &minute);
  fflush(stdin);
  if (hour > 12)
  {
    hour = hour - 12;
  }
  float angle_hourhand = hour*30 + minute/2;
  float angle_minutehand = minute*6;
  float angle_difference = fabs(angle_hourhand - angle_minutehand);
  if (angle_difference > 180)
  {
    angle_difference = 360 - angle_difference;
  }
  printf("The angle between the hands is %.1f degrees.\n",angle_difference);
  getchar();
  return 0;
}