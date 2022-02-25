#include "typewise-alert.h"

BreachType inferBreach(double value, double lowerLimit, double upperLimit) {
  if(value < lowerLimit) {
    return TOO_LOW;
  }
  if(value > upperLimit) {
    return TOO_HIGH;
  }
  return NORMAL;
}

BreachType classifyTemperatureBreach(
    CoolingType coolingType, double temperatureInC) {
  int lowerLimit = 0;
  int upperLimit = 0;
  TempClassification(coolingType,&lowerLimit,&upperLimit);
  return inferBreach(temperatureInC, lowerLimit, upperLimit);
}

void TempClassification(CoolingType coolingType,int *lowerLimit,int *upperLimit)
{
   switch(coolingType) {
    case PASSIVE_COOLING:
      *lowerLimit = 0;
      *upperLimit = 35;
      break;
    case HI_ACTIVE_COOLING:
      *lowerLimit = 0;
      *upperLimit = 45;
      break;
    case MED_ACTIVE_COOLING:
      *lowerLimit = 0;
      *upperLimit = 40;
      break;
  }
}
