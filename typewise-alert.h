#pragma once

typedef enum {
  PASSIVE_COOLING,
  HI_ACTIVE_COOLING,
  MED_ACTIVE_COOLING
} CoolingType;

typedef enum {
  NORMAL,
  TOO_LOW,
  TOO_HIGH
} BreachType;

BreachType inferBreach(double value, double lowerLimit, double upperLimit);
BreachType classifyTemperatureBreach(CoolingType coolingType, double temperatureInC);

typedef enum {
  TO_CONTROLLER,
  TO_EMAIL
} AlertTarget;

typedef struct {
  CoolingType coolingType;
  char brand[48];
} BatteryCharacter;

typedef struct{
  int Too_Low_Cnt;
  int Too_High_Cnt;
  int Normal_Cnt;
  int Controller_Feedback;
}TestCounter;
extern TestCounter TestCounter_Ver;
void checkAndAlert(AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC,void (*)(BreachType),void (*)(BreachType));

void sendToController(BreachType breachType);
void sendToEmail(BreachType breachType);
void sendToEmail_Test(BreachType breachType);
void Targetalert(AlertTarget alertTarget,void (*)(BreachType),void (*)(BreachType),BreachType breachType);
void TempClassification(CoolingType coolingType,int *lowerLimit,int *upperLimit);
void sendToController_Test(BreachType breachType);
void Reset_Counter();
