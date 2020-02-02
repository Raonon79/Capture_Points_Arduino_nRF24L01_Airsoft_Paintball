//nRF24L01 + PA + LNA - Receiver tester
//Author: Martin Chlebovec
//E-mail: martinius96@gmail.com
//Webpage: https://arduino.php5.sk/airsoft-wifi.php?lang=en

#include <SPI.h>
#include "RF24.h"
int prijem;
const int buzzer = 2;
#define CE 4
#define CS 3
RF24 nRF(CE, CS);
byte adresaPrijimac[] = "prijimac00";
byte adresaVysilac[] = "vysilac00";
void setup() {
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
  nRF.begin();
  nRF.setDataRate( RF24_250KBPS );
  nRF.setPALevel(RF24_PA_LOW);
  nRF.openWritingPipe(adresaPrijimac);
  nRF.openReadingPipe(1, adresaVysilac);
  nRF.startListening();
}

void loop() {
  unsigned long odezva;
  if ( nRF.available()) {
    while (nRF.available()) {
      nRF.read( &prijem, sizeof(prijem) );
    }
    Serial.print("Prijata volba: ");
    Serial.print(prijem);
    switch ( prijem ) {
      case 1:
        odezva = millis();
        tone(buzzer, 50, 500);
        break;
      case 2:
        odezva = millis() / 1000;
        break;
      case 3:
        odezva = micros();
        break;
      default:
        odezva = 0;
        break;
    }
    nRF.stopListening();
    nRF.write( &odezva, sizeof(odezva) );
    nRF.startListening();
  }
}
