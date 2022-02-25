#include "typewise-alert.h"

void checkAndAlert(
    AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC,void (*sendToController)(BreachType),void (*sendToEmail)(BreachType)) {
    BreachType breachType = classifyTemperatureBreach(batteryChar.coolingType, temperatureInC);
    Targetalert(alertTarget,sendToController,sendToEmail,breachType);
}

