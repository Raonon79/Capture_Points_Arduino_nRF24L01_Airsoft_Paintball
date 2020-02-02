//nRF24L01 + PA + LNA - Transmitter tester
//Author: Martin Chlebovec
//E-mail: martinius96@gmail.com
//Webpage: https://arduino.php5.sk/airsoft-wifi.php?lang=en

#include <SPI.h>
#include "RF24.h"
#define CE 4
#define CS 3
RF24 nRF(CE, CS);
byte adresaPrijimac[] = "prijimac00";
byte adresaVysilac[] = "vysilac00";
void setup() {
  Serial.begin(9600);
  nRF.begin();
  nRF.setDataRate( RF24_250KBPS );
  nRF.setPALevel(RF24_PA_LOW);
  nRF.openWritingPipe(adresaVysilac);
  nRF.openReadingPipe(1, adresaPrijimac);
  nRF.startListening();
}

void loop() {
  for (int i = 0; i < 4; i++ ) {
    nRF.stopListening();
    unsigned long casZacatek = micros();
    if (!nRF.write( &i, sizeof(i) )) {
      Serial.println("Error at sending datas!");
    }
    nRF.startListening();
    unsigned long casCekaniOdezvy = micros();
    boolean timeout = false;
    while ( ! nRF.available() ) {
      if (micros() - casCekaniOdezvy > 200000 ) {
        timeout = true;
        break;
      }
    }
    if ( timeout ) {
      Serial.println("Error at saving datas!");
    }
    else {

      unsigned long prijataData;
      nRF.read( &prijataData, sizeof(prijataData) );
      unsigned long casKonec = micros();
      Serial.print("Datas sent: ");
      Serial.print(i);
      Serial.print(", Datas received: ");
      Serial.println(prijataData);
      Serial.print("Session duration: ");
      Serial.print(casKonec - casZacatek);
      Serial.println(" microseconds.");
    }
    delay(200);
  }
}
