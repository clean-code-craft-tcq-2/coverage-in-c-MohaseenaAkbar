#include "typewise-alert.h"
#include <stdio.h>

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

void TempClassification(CoolingType coolingType,int* lowerLimit,int* upperLimit)
{
   switch(coolingType) {
    case PASSIVE_COOLING:
      lowerLimit = 0;
      upperLimit = 35;
      break;
    case HI_ACTIVE_COOLING:
      lowerLimit = 0;
      upperLimit = 45;
      break;
    case MED_ACTIVE_COOLING:
      lowerLimit = 0;
      upperLimit = 40;
      break;
  }
}
  
void checkAndAlert(
    AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC,void (*sendToController)(BreachType),void (*sendToEmail)(BreachType)) {
  BreachType breachType = classifyTemperatureBreach(
    batteryChar.coolingType, temperatureInC
  );
  void alertTarget(alertTarget,(*sendToController)(BreachType),(*sendToEmail)(BreachType));
}

void alertTarget(AlertTarget alertTarget,void (*sendToController)(BreachType),void (*sendToEmail)(BreachType))
{
  switch(alertTarget) {
    case TO_CONTROLLER:
      (*sendToController)(breachType);
      break;
    case TO_EMAIL:
      (*sendToEmail)(breachType);
      break;
  }

void sendToController(BreachType breachType) {
  const unsigned short header = 0xfeed;
  printf("%x : %x\n", header, breachType);
}
void sendToController_Test(BreachType breachType) {
  TestCounter_Ver.Controller_Feedback++;
}


void sendToEmail_Test(BreachType breachType) {
  switch(breachType) {
    case TOO_LOW:
      printf("Hi, the temperature is too low\n");
      TestCounter_Ver.Too_Low_Cnt++;
      break;
    case TOO_HIGH:
      printf("Hi, the temperature is too high\n");
      TestCounter_Ver.Too_High_Cnt++;
      break;
    case NORMAL:
      TestCounter_Ver.Normal_Cnt++;
      break;
  }
}

void Reset_Counter()
{
  TestCounter_Ver.Too_Low_Cnt=0;
  TestCounter_Ver.Too_High_Cnt=0
  TestCounter_Ver.Normal_Cnt=0;
  TestCounter_Ver.Controller_Feedback=0;
}
  
  void sendToEmail(BreachType breachType) {
  const char* recepient = "a.b@c.com";
  switch(breachType) {
    case TOO_LOW:
      printf("To: %s\n", recepient);
      printf("Hi, the temperature is too low\n");
      break;
    case TOO_HIGH:
      printf("To: %s\n", recepient);
      printf("Hi, the temperature is too high\n");
      break;
    case NORMAL:
      break;
  }
}
