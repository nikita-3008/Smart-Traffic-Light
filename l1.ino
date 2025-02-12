#define RED 9
#define YELLOW 10
#define GREEN 11
#define BUTTON 2
#define TRIG 6
#define ECHO 7

long duration;
int distance;
unsigned long lastDetectionTime = 0;

void setup() {
  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BUTTON, INPUT_PULLUP);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  Serial.begin(9600);
}

int getDistance() {
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  duration = pulseIn(ECHO, HIGH);
  return duration * 0.034 / 2;
}

void loop() {
  distance = getDistance();
  Serial.print("Distance: ");
  Serial.println(distance);

  if (distance < 50) {
    lastDetectionTime = millis();  // Reset timer when a vehicle is detected

    // Normal Traffic Light Sequence
    digitalWrite(GREEN, HIGH);
    digitalWrite(YELLOW, LOW);
    digitalWrite(RED, LOW);
    delay(5000);

    digitalWrite(GREEN, LOW);
    digitalWrite(YELLOW, HIGH);
    delay(2000);

    digitalWrite(YELLOW, LOW);
    digitalWrite(RED, HIGH);
    delay(5000);
  } 
  
  else if (millis() - lastDetectionTime > 30000) {
    // If no vehicle detected for 30 sec, keep Red light on
    digitalWrite(RED, HIGH);
    digitalWrite(GREEN, LOW);
    digitalWrite(YELLOW, LOW);
  }

  // Pedestrian button check
  if (digitalRead(BUTTON) == LOW) {
    digitalWrite(GREEN, LOW);
    digitalWrite(YELLOW, LOW);
    digitalWrite(RED, HIGH);
    delay(5000);
  }
}
