const int red = 10;
const int yellow = 9;
const int green = 8;
const int manualmode = 3;
const int automode = 2;
const int buttonGreen = 5;
const int buttonYellow = 6;
const int buttonRed = 7;
int c=0;

bool isManualMode = true;  // Start in manual mode
bool greenState = LOW;
bool yellowState = LOW;
bool redState = LOW;

void setup() {
  Serial.begin(9600); // Initialize serial communication for debugging
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(manualmode, INPUT_PULLUP); // Button to switch to manual mode
  pinMode(automode, INPUT_PULLUP);   // Button to switch to automatic mode
  pinMode(buttonGreen, INPUT_PULLUP);  // Pushbutton for green LED in manual mode
  pinMode(buttonYellow, INPUT_PULLUP); // Pushbutton for yellow LED in manual mode
  pinMode(buttonRed, INPUT_PULLUP);    // Pushbutton for red LED in manual mode
}

void loop() {
  // Check if the automatic mode button is pressed to switch to automatic mode
  if (digitalRead(automode) == LOW) {
    isManualMode = false;
    delay(500); // Debounce delay
    Serial.println("Switched to Automatic Mode");
  }

  if (isManualMode) {
    // Manual Mode
    if (digitalRead(buttonGreen) == LOW) {
      if (c>0)
      {
        redState = !redState;
      }
      greenState = !greenState;
      yellowState = yellowState;
      redState = redState;
      digitalWrite(green, greenState);
      digitalWrite(yellow, yellowState);
      digitalWrite(red, redState);
      Serial.print("Green LED ");
      Serial.println(greenState == HIGH ? "ON" : "OFF");
      delay(500); // Debounce delay
    }
    if (digitalRead(buttonYellow) == LOW) {
      greenState = !greenState;
      yellowState = !yellowState;
      redState = redState;
      digitalWrite(yellow, yellowState);
      digitalWrite(green, greenState);
      digitalWrite(yellow, yellowState);
      digitalWrite(red, redState);
      Serial.print("Yellow LED ");
      Serial.println(yellowState == HIGH ? "ON" : "OFF");
      delay(500); // Debounce delay
    }
    if (digitalRead(buttonRed) == LOW) {
      greenState = greenState;
      yellowState = !yellowState;
      redState = !redState;
      digitalWrite(red, redState);
      digitalWrite(green, greenState);
      digitalWrite(yellow, yellowState);
      digitalWrite(red, redState);
      Serial.print("Red LED ");
      Serial.println(redState == HIGH ? "ON" : "OFF");
      delay(500); // Debounce delay
      c++;
    }
      
  } else {
    // Automatic Mode
    digitalWrite(green, HIGH);
    delay(5000);
    digitalWrite(green, LOW);
    digitalWrite(yellow, HIGH);
    delay(2000);
    digitalWrite(yellow, LOW);
    digitalWrite(red, HIGH);
    delay(7000);
    digitalWrite(red, LOW);

    // Check if the manual mode button is pressed to switch back to manual mode
    if (digitalRead(manualmode) == LOW) {
      isManualMode = true;
      delay(500); // Debounce delay
      Serial.println("Switched to Manual Mode");
    }
  }
}
