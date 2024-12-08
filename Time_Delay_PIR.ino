#define sensor_pir 7
int memory_pir;

unsigned long waktu_millis_sebelumnya100 = 0;
unsigned long waktu_millis_sekarang100 = 0;
const long jangka_waktu100ms = 100;

unsigned long waktu_millis_sebelumnya1000 = 0;
unsigned long waktu_millis_sekarang1000 = 0;
const long jangka_waktu1000ms = 1000;

void setup() {
  Serial.begin(115200);
  pinMode(sensor_pir, INPUT);
  pinMode(13, OUTPUT);
}

void loop() {
  waktu_millis_sekarang100 = millis();
  if (waktu_millis_sekarang100 - waktu_millis_sebelumnya100 >= jangka_waktu100ms )
  {
    if (digitalRead(sensor_pir) == 1)
    {
      if ( memory_pir < 100) {
        memory_pir++;
      }
    }
    waktu_millis_sebelumnya100 = waktu_millis_sekarang100;
  }
  waktu_millis_sekarang1000 = millis();
  if (waktu_millis_sekarang1000 - waktu_millis_sebelumnya1000 >= jangka_waktu1000ms )
  {
    if (digitalRead(sensor_pir) == 0)
    {
      if ( memory_pir > 0) {
        memory_pir--;
      }
    }
    waktu_millis_sebelumnya1000 = waktu_millis_sekarang1000;
  }
  digitalWrite(13, !memory_pir);
  Serial.print("memory_pir = "); Serial.print(memory_pir); Serial.print("  ");
  Serial.println(digitalRead(sensor_pir));
}
