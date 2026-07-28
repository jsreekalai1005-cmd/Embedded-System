const int buttonA = 2;
const int buttonB = 3;

const int greenLED = 8;
const int redLED = 9;

void setup() {
  pinMode(buttonA, INPUT_PULLUP);
  pinMode(buttonB, INPUT_PULLUP);

  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);

  digitalWrite(greenLED, HIGH);
  digitalWrite(redLED, LOW);

  Serial.begin(9600);
  Serial.println("ECU Race Condition Simulation");
}

void loop() {

  if (digitalRead(buttonA) == LOW) {
    unsigned long startTime = millis();

    while (millis() - startTime < 1000) {

      if (digitalRead(buttonB) == LOW) {

        Serial.println("Race Condition Detected!");
        Serial.println("Vehicle Stall!");

        digitalWrite(greenLED, LOW);
        digitalWrite(redLED, HIGH);

        delay(2000);

        digitalWrite(redLED, LOW);
        digitalWrite(greenLED, HIGH);

        while (digitalRead(buttonA) == LOW || digitalRead(buttonB) == LOW);

        delay(200);

        break;
      }
    }
  }
}