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

void checkAndAlert(
    AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC,void (*sendToController)(BreachType),void (*sendToEmail)(BreachType)) {
    BreachType breachType = classifyTemperatureBreach(batteryChar.coolingType, temperatureInC);
    Targetalert(alertTarget,sendToController,sendToEmail,breachType);
}

