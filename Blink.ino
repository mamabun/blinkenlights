/*
  Geekmas lights

  Jennifer "mamabun" Rabbitt

  Just an emulation of the blinking lights you can get from the local dollar store
  
*/

// most launchpads have a red LED
#define LED RED_LED
short randNumber;
short blinkrand;
  
// the setup routine runs once when you press reset:
void setup() {                
  pinMode(LED, OUTPUT);
  Serial.begin(9600); // Setup serial to monitor things and stuff
  randomSeed(analogRead(6)); //Get random seeds from thin air. Like magic     
}

void slowblink()  {
  digitalWrite(LED, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);               // wait for a second
  digitalWrite(LED, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);               // wait for a second 
}

void fastblink()  {
  digitalWrite(LED, HIGH);
  delay(500);
  digitalWrite(LED, LOW);
  delay(500);
}

void randblink()  {
  digitalWrite(LED, HIGH);
  blinkrand = random(1001);
  delay(blinkrand);
  digitalWrite(LED,LOW);
  blinkrand = random(1001);
  delay(blinkrand);
}

void justON() {
  digitalWrite(LED, HIGH);
  delay(5000);
}
// the loop routine runs over and over again forever:
void loop() {

  //Random number testing area(here be dragons)
   // print a random number from 0 to 3
   Serial.print("Random number is = ");
   randNumber = random(4);
   Serial.println(randNumber); // print a random number from 0 to 2

  if (randNumber == 0) {
    Serial.print("Slowblink");
    Serial.println(); 
    slowblink();
    slowblink();
    slowblink();
    slowblink();
    slowblink();
    return;
  }
  else if (randNumber == 1) {
    Serial.print("Fastblink");
    Serial.println();
    fastblink();
    fastblink();
    fastblink();
    fastblink();
    fastblink();
    return;
  }
  else if (randNumber == 2) {
    Serial.print("Random blink");
    Serial.println(); 
    randblink();
    randblink();
    randblink();
    randblink();
    randblink();
    return;
  }
  else if (randNumber == 3) {
    Serial.print("Just on");
    Serial.println();
    justON();
    return;
  }
  else {
    Serial.print("I don't know how I got here. I'm not good with computer");
    Serial.println(); 
    slowblink();
    fastblink();
    randblink();
  }
}
