#define MIC A0

int sig = A0;

void setup() {
 pinMode(0, OUTPUT);
 pinMode(1, OUTPUT);
 pinMode(2, OUTPUT);
 pinMode(3, OUTPUT);
 pinMode(4, OUTPUT);
 pinMode(5, OUTPUT);
 pinMode(6, OUTPUT);

}

void led() {
 sig = analogRead(MIC)*250;

 if (sig>60000)  {digitalWrite(0, HIGH);} else {digitalWrite(0, LOW);}
 if (sig>90000)  {digitalWrite(1, HIGH);} else {digitalWrite(1, LOW);}
 if (sig>130000) {digitalWrite(2, HIGH);} else {digitalWrite(2, LOW);}
 if (sig>160000) {digitalWrite(3, HIGH);} else {digitalWrite(3, LOW);}
 if (sig>190000) {digitalWrite(4, HIGH);} else {digitalWrite(4, LOW);}
 if (sig>220000) {digitalWrite(5, HIGH);} else {digitalWrite(5, LOW);}
 if (sig>260000) {digitalWrite(6, HIGH);} else {digitalWrite(6, LOW);}
}

void loop() {
 led();
}
