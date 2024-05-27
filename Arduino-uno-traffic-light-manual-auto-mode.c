const int red = 10;
const int yellow = 9;
const int green = 8;
const int manualmode = 3;
const int automode = 2;
const int buttonGreen = 5;
const int buttonYellow = 6;
const int buttonRed = 7;

bool isManualMode = true;  // Start in manual mode

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
      digitalWrite(green, HIGH);
      Serial.println("Green LED ON");
      delay(5000);
    } else {
      digitalWrite(green, LOW);
      Serial.println("Green LED OFF");
    }
    if (digitalRead(buttonYellow) == LOW) {
      digitalWrite(yellow, HIGH);
      Serial.println("Yellow LED ON");
      delay(5000);
    } else {
      digitalWrite(yellow, LOW);
      Serial.println("Yellow LED OFF");
    }
    if (digitalRead(buttonRed) == LOW) {
      digitalWrite(red, HIGH);
      Serial.println("Red LED ON");
    } else {
      digitalWrite(red, LOW);
      Serial.println("Red LED OFF");
      delay(5000);
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
      delay(2000);
    }
  }
}
