/* Engelden Kaçan Araç */
int sure = 0;
int mesafe = 0;

const int trig_pin = 3;
const int echo_pin = 2;
const int sag_enable = 11;  // ENABLE A
const int sag_ileri = 10;   // INPUT 1
const int sag_geri = 9;     // INPUT 2
const int sol_ileri = 8;    // INPUT 3
const int sol_geri = 7;     // INPUT 4
const int sol_enable = 6;   // ENABLE B
const int buzzer = 5;

void setup() {
  pinMode(buzzer, OUTPUT);
  pinMode(trig_pin, OUTPUT);
  pinMode(echo_pin, INPUT);
  pinMode(sag_ileri, OUTPUT);
  pinMode(sag_geri, OUTPUT);
  pinMode(sol_ileri, OUTPUT);
  pinMode(sol_geri, OUTPUT);
  pinMode(sag_enable, OUTPUT);
  pinMode(sol_enable, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pin, LOW);
  sure = pulseIn(echo_pin, HIGH);
  mesafe = (sure / 2) / 29.1;
  Serial.println(mesafe);


  if (mesafe < 20) {  // mesafe 20 cm den küçükse
    // motorlar kitlenerek araç durdurulur

    stop();
    delay(500);
    geri();
    delay(500);
    sag();
    delay(500);
  }

  else {
    ileri();
  }
}
void stop() {
  digitalWrite(buzzer, HIGH);
  digitalWrite(sag_ileri, LOW);
  digitalWrite(sag_geri, LOW);
  digitalWrite(sol_ileri, LOW);
  digitalWrite(sol_geri, LOW);
}
void sag() {
  // araç sağa döndürülür
  digitalWrite(sag_ileri, LOW);
  digitalWrite(sag_geri, HIGH);
  digitalWrite(sol_ileri, HIGH);
  digitalWrite(sol_geri, LOW);
  analogWrite(sag_enable, 200);  // motor hızları 200 PWM
  analogWrite(sol_enable, 200);
}
void ileri() {
  digitalWrite(sag_ileri, HIGH);
  digitalWrite(sag_geri, LOW);
  digitalWrite(sol_ileri, HIGH);
  digitalWrite(sol_geri, LOW);
  analogWrite(sag_enable, 255);  // motor hızları 255 PWM
  analogWrite(sol_enable, 255);
  digitalWrite(buzzer, LOW);
}
void geri() {
  digitalWrite(sag_ileri, LOW);
  digitalWrite(sag_geri, HIGH);
  digitalWrite(sol_ileri, LOW);
  digitalWrite(sol_geri, HIGH);
  analogWrite(sag_enable, 150);  // motor hızları 200 PWM
  analogWrite(sol_enable, 150);
}