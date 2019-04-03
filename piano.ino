#include "pins_arduino.h" // Arduino pre-1.0 needs this

uint8_t readCapacitivePin(int pinToMeasure) {
  volatile uint8_t* port;
  volatile uint8_t* ddr;
  volatile uint8_t* pin;
  byte bitmask;

  port = portOutputRegister(digitalPinToPort(pinToMeasure));
  ddr = portModeRegister(digitalPinToPort(pinToMeasure));
  bitmask = digitalPinToBitMask(pinToMeasure);
  pin = portInputRegister(digitalPinToPort(pinToMeasure));
  *port &= ~(bitmask);
  *ddr  |= bitmask;

  delay(1);

  uint8_t SREG_old = SREG;

  noInterrupts();

  *ddr &= ~(bitmask);
  *port |= bitmask;

  uint8_t cycles = 17;

  if (*pin & bitmask) {
    cycles =  0;
  }

  else if (*pin & bitmask) {
    cycles =  1;
  }

  else if (*pin & bitmask) {
    cycles =  2;
  }

  else if (*pin & bitmask) {
    cycles =  3;
  }

  else if (*pin & bitmask) {
    cycles =  4;
  }

  else if (*pin & bitmask) {
    cycles =  5;
  }

  else if (*pin & bitmask) {
    cycles =  6;
  }

  else if (*pin & bitmask) {
    cycles =  7;
  }

  else if (*pin & bitmask) {
    cycles =  8;
  }

  else if (*pin & bitmask) {
    cycles =  9;
  }

  else if (*pin & bitmask) {
    cycles = 10;
  }

  else if (*pin & bitmask) {
    cycles = 11;
  }

  else if (*pin & bitmask) {
    cycles = 12;
  }

  else if (*pin & bitmask) {
    cycles = 13;
  }

  else if (*pin & bitmask) {
    cycles = 14;
  }

  else if (*pin & bitmask) {
    cycles = 15;
  }

  else if (*pin & bitmask) {
    cycles = 16;
  }

  SREG = SREG_old;

  *port &= ~(bitmask);

  *ddr  |= bitmask;

  return cycles;
}

int limiar = 2;
int buzzer = 10;

void setup() {
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
}

void loop(){
  Serial.print(readCapacitivePin(4));
  if (readCapacitivePin(4) > 2) {
    
    tone(buzzer, 261);
    delay(200);
    noTone(buzzer); 
  }

  if (readCapacitivePin(5) > 5) {
    tone(buzzer, 300);
    delay(200);
    noTone(buzzer); 
  }

  if (readCapacitivePin(6) > 5) {
    tone(buzzer, 400);
    delay(200);
    noTone(buzzer); 
  }

  if (readCapacitivePin(7) > 5) {
    tone(buzzer, 500);
    delay(200);
    noTone(buzzer); 
  }

  if (readCapacitivePin(8) > 5) {
    tone(buzzer, 600);
    delay(200);
    noTone(buzzer); 
  }

  if (readCapacitivePin(9) > 5) {
    tone(buzzer, 700);
    delay(200);
    noTone(buzzer); 
  }
}
