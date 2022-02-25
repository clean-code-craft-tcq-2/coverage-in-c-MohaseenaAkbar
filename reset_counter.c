#include "typewise-alert.h"
void Reset_Counter()
{
  TestCounter_Ver.Too_Low_Cnt=0;
  TestCounter_Ver.Too_High_Cnt=0;
  TestCounter_Ver.Normal_Cnt=0;
  TestCounter_Ver.Controller_Feedback=0;
}
