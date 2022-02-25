#include "typewise-alert.h"
#include <stdio.h>

void Targetalert(AlertTarget alertTarget,void (*sendToController)(BreachType),void (*sendToEmail)(BreachType),BreachType breachType)
{
  switch(alertTarget) {
    case TO_CONTROLLER:
      (*sendToController)(breachType);
      break;
    case TO_EMAIL:
      (*sendToEmail)(breachType);
      break;
  }
}
void sendToController(BreachType breachType) {
  const unsigned short header = 0xfeed;
  printf("%x : %x\n", header, breachType);
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
