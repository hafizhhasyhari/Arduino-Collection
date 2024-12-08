// Sistem Antisipasi Banjir
// dibuat : hafizhhasyhari
#include <LiquidCrystal.h>

// Pin LCD
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// Sensor ultrasonik
const int trigPins[3] = {9, 7, 5};
const int echoPins[3] = {10, 8, 6};

// Buzzer dan LED
const int buzzer = 4;
const int ledRed = 3;

// Fungsi pengukuran jarak
float measureDistance(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  return duration * 0.034 / 2.0; // Jarak dalam cm
}

// Fungsi greedy untuk mencari lokasi risiko tertinggi
int findCriticalLocation(float distances[], int size) {
  int index = 0;
  for (int i = 1; i < size; i++) {
    if (distances[i] < distances[index]) {
      index = i;
    }
  }
  return index; // Lokasi dengan jarak air terdekat (risiko tertinggi)
}

void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600);

  for (int i = 0; i < 3; i++) {
    pinMode(trigPins[i], OUTPUT);
    pinMode(echoPins[i], INPUT);
  }

  pinMode(buzzer, OUTPUT);
  pinMode(ledRed, OUTPUT);

  lcd.print("Flood System");
  delay(2000);
  lcd.clear();
}

void loop() {
  float distances[3];
  for (int i = 0; i < 3; i++) {
    distances[i] = measureDistance(trigPins[i], echoPins[i]);
  }

  // Temukan lokasi dengan risiko tertinggi
  int criticalLocation = findCriticalLocation(distances, 3);

  lcd.setCursor(0, 0);
  lcd.print("Loc: ");
  lcd.print(criticalLocation);
  lcd.print(" Dist: ");
  lcd.print(distances[criticalLocation]);

  if (distances[criticalLocation] < 10.0) {
    digitalWrite(ledRed, HIGH);
    digitalWrite(buzzer, HIGH);
    lcd.setCursor(0, 1);
    lcd.print("FLOOD ALERT!");
  } else {
    digitalWrite(ledRed, LOW);
    digitalWrite(buzzer, LOW);
    lcd.setCursor(0, 1);
    lcd.print("All Safe");
  }

  delay(2000);
  lcd.clear();
}
