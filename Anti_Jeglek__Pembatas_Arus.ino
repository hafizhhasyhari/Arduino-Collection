unsigned long interval = 500;
unsigned long satumS = 1;
unsigned long previousMillis = 0;
unsigned long currentMillis = 0;

int timer, A, rrarus;
bool ledState = false;
void setup() {
  pinMode(A1, INPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(13, OUTPUT);
  digitalWrite(13, ledState);
  digitalWrite(6, 1); digitalWrite(5, 1);
}
void loop() {
  A = analogRead(A1);
  if (A > 800 || A < 200) {
    digitalWrite(6, 0);
    if (A > 800 || A < 200) {
      delay(5000);
    }
  }
  else {
    digitalWrite(6, 1);
  }
  if (A > 540 || A < 460) {
    if (timer < 10) {
      timer = timer + 1;
    }
    if (timer > 0) {
      digitalWrite(5, 0);
    }
  }
  currentMillis = millis();
  if ((unsigned long)(currentMillis - previousMillis) >= interval) {
    ledState = !ledState;
    digitalWrite(13, ledState);
    previousMillis = millis();
    if (A < 530 || A > 480) {
      if (timer > 0) {
        timer = timer - 1;
      }
      if (timer == 0) {
        digitalWrite(5, 1);
      }
    }
  }
  currentMillis = millis();
  if ((unsigned long)(currentMillis - previousMillis) >= satumS) {
    previousMillis = millis();
    rrarus = A;

  }
}
