//Projectslearner.com 
int red = 10;
int yellow = 9;
int green = 8;

void setup() {
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
}

void loop() {
  digitalWrite(green, HIGH);
  delay(5000);
  digitalWrite(green, LOW);
  digitalWrite(yellow, HIGH);
  delay(2000);
  digitalWrite(yellow, LOW);
  digitalWrite(red, HIGH);
  delay(7000);
  digitalWrite(red, LOW);
}
