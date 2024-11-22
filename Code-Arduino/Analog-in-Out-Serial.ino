/*
Input analog, output analog, output serial

Membaca pin input analog, memetakan hasil ke rentang dari 0 hingga 255
dan menggunakan hasil untuk mengatur modulasi lebar pulsa (PWM) dari pin output.
Juga mencetak hasil ke monitor serial.

Rangkaian:
* potensiometer terhubung ke pin analog 0.
Pin tengah potensiometer menuju ke pin analog.
Pin samping potensiometer menuju ke +5V dan ground
* LED terhubung dari pin digital 9 ke ground

Hardware yang diperlukan 
Arduino or Genuino Board
Potentiometer
Red LED
220 ohm resistor

 */
// Konstanta ini tidak akan berubah. Konstanta ini digunakan untuk memberi nama
// pada pin yang digunakan:
const int analogInPin = A0;       // Pin input analog tempat potensiometer terpasang
const int analogOutPin = 9;       // Pin output analog tempat LED terpasang


int sensorValue = 0; // nilai yang dibaca dari pot
int outputValue = 0; // nilai keluaran ke PWM (analog out)

void setup() {
// inisialisasi komunikasi serial pada 9600 bps:
Serial.begin(9600);
}

void loop() {

// baca nilai analog in:
sensorValue = analogRead(analogInPin);
// petakan ke rentang analog out:
outputValue = map(sensorValue, 0, 1023, 0, 255);
// ubah nilai analog out:
analogWrite(analogOutPin, outputValue);

// cetak hasil ke monitor serial:
Serial.print("sensor = ");
Serial.print(sensorValue);
Serial.print("\t output = ");
Serial.println(outputValue);

// tunggu 2 milidetik sebelum loop berikutnya
// agar konverter analog-ke-digital berhenti
// setelah pembacaan terakhir:
delay(2); }
