#include <LiquidCrystal.h>

const int trigPin = 9;
const int echoPin = 10;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// set your threshold here
float threshold = 50.0;

void setup()
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  lcd.begin(16, 2);

  lcd.print("Distance Meter");
  delay(2000);
  lcd.clear();
}

void loop()
{
  long duration;
  float distanceCm;

  // Trigger ultrasonic pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  // Read echo (with timeout)
  duration = pulseIn(echoPin, HIGH, 30000);

  if (duration == 0)
  {
    lcd.setCursor(0, 0);
    lcd.print("No Signal      ");

    lcd.setCursor(0, 1);
    lcd.print("Check Sensor   ");
    delay(500);
    return;
  }

  // Calculate distance
  distanceCm = duration * 0.034 / 2;

  // -------- LCD LINE 1 --------
  lcd.setCursor(0, 0);
  lcd.print("Distance:");
  lcd.print(distanceCm);
  lcd.print("cm   ");

  // -------- LCD LINE 2 --------
  lcd.setCursor(0, 1);
  lcd.print("Threshold :");
  lcd.print(threshold);
  lcd.print("cm   ");

  delay(500);
}
