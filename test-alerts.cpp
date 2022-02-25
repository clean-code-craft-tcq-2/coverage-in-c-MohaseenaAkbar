#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "typewise-alert.h"

TEST_CASE("infers the breach according to limits") {
  REQUIRE(inferBreach(12, 20, 30) == TOO_LOW);
  REQUIRE(inferBreach(40, 20, 30) == TOO_HIGH);
}

TEST_CASE("Classify the breach") {
  REQUIRE(classifyTemperatureBreach(PASSIVE_COOLING, 20) == NORMAL);
  REQUIRE(classifyTemperatureBreach(PASSIVE_COOLING, 35) == NORMAL);
  REQUIRE(classifyTemperatureBreach(HI_ACTIVE_COOLING, 20) == NORMAL);
  REQUIRE(classifyTemperatureBreach(HI_ACTIVE_COOLING, 45) == NORMAL);
  REQUIRE(classifyTemperatureBreach(MED_ACTIVE_COOLING, 20) == NORMAL);
  REQUIRE(classifyTemperatureBreach(MED_ACTIVE_COOLING, 40) == NORMAL);
  REQUIRE(classifyTemperatureBreach(PASSIVE_COOLING, 0) == NORMAL);
  REQUIRE(classifyTemperatureBreach(PASSIVE_COOLING, -1) == TOO_LOW);
  REQUIRE(classifyTemperatureBreach(HI_ACTIVE_COOLING, 0) == NORMAL);
  REQUIRE(classifyTemperatureBreach(HI_ACTIVE_COOLING, -1) == TOO_LOW);
  REQUIRE(classifyTemperatureBreach(MED_ACTIVE_COOLING, 0) == NORMAL);
  REQUIRE(classifyTemperatureBreach(MED_ACTIVE_COOLING, -1) == TOO_LOW);
  REQUIRE(classifyTemperatureBreach(PASSIVE_COOLING, 38) == TOO_HIGH);
  REQUIRE(classifyTemperatureBreach(HI_ACTIVE_COOLING, 48) == TOO_HIGH);
  REQUIRE(classifyTemperatureBreach(MED_ACTIVE_COOLING, 42) == TOO_HIGH);
}
TEST_CASE("check and alert")

{
  BatteryCharacter Batt;
  Batt.coolingType =PASSIVE_COOLING;
  void (*sendToController)(BreachType) =sendToController_Test;
  void (*sendToEmail)(BreachType) =sendToEmail_Test;
  checkAndAlert(TO_EMAIL,Batt,25,sendToController,sendToEmail);
  REQUIRE(TestCounter_Ver.Too_Low_Cnt==0);
  REQUIRE(TestCounter_Ver.Too_High_Cnt==0);
  REQUIRE(TestCounter_Ver.Normal_Cnt==1);
  REQUIRE(TestCounter_Ver.Controller_Feedback==0);
  
  Reset_Counter();
  checkAndAlert(TO_CONTROLLER,Batt,25,sendToController,sendToEmail);
  REQUIRE(TestCounter_Ver.Too_Low_Cnt==0);
  REQUIRE(TestCounter_Ver.Too_High_Cnt==0);
  REQUIRE(TestCounter_Ver.Normal_Cnt==0);
  REQUIRE(TestCounter_Ver.Controller_Feedback==1);
  
  Reset_Counter();
  Batt.coolingType =HI_ACTIVE_COOLING;
  checkAndAlert(TO_EMAIL,Batt,25,sendToController,sendToEmail);
  REQUIRE(TestCounter_Ver.Too_Low_Cnt==0);
  REQUIRE(TestCounter_Ver.Too_High_Cnt==0);
  REQUIRE(TestCounter_Ver.Normal_Cnt==1);
  REQUIRE(TestCounter_Ver.Controller_Feedback==0);
  
  Reset_Counter();
  checkAndAlert(TO_CONTROLLER,Batt,25,sendToController,sendToEmail);
  REQUIRE(TestCounter_Ver.Too_Low_Cnt==0);
  REQUIRE(TestCounter_Ver.Too_High_Cnt==0);
  REQUIRE(TestCounter_Ver.Normal_Cnt==0);
  REQUIRE(TestCounter_Ver.Controller_Feedback==1);
  
  Reset_Counter();
  Batt.coolingType =MED_ACTIVE_COOLING;
  checkAndAlert(TO_EMAIL,Batt,25,sendToController,sendToEmail);
  REQUIRE(TestCounter_Ver.Too_Low_Cnt==0);
  REQUIRE(TestCounter_Ver.Too_High_Cnt==0);
  REQUIRE(TestCounter_Ver.Normal_Cnt==1);
  REQUIRE(TestCounter_Ver.Controller_Feedback==0);
  
  Reset_Counter();
  checkAndAlert(TO_CONTROLLER,Batt,25,sendToController,sendToEmail);
  REQUIRE(TestCounter_Ver.Too_Low_Cnt==0);
  REQUIRE(TestCounter_Ver.Too_High_Cnt==0);
  REQUIRE(TestCounter_Ver.Normal_Cnt==0);
  REQUIRE(TestCounter_Ver.Controller_Feedback==1);
  
}
