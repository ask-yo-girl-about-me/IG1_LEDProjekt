#define MIC A0

int db_value = A0;

void setup() {
 Serial.begin(9600);
 pinMode(0, OUTPUT);
 pinMode(1, OUTPUT);
 pinMode(2, OUTPUT);
 pinMode(3, OUTPUT);
 pinMode(4, OUTPUT);
 pinMode(5, OUTPUT);
 pinMode(6, OUTPUT);

}

void led() {
  // read the sensors values
  long db_value = 0;
    for(int i=0; i<32; i++)
    {
        db_value += analogRead(A0);
    }
    db_value >>= 5;
    Serial.println(db_value);
    delay(10);
     if (db_value>200) {digitalWrite(0, HIGH);} else {digitalWrite(0, LOW);}
     if (db_value>250) {digitalWrite(1, HIGH);} else {digitalWrite(1, LOW);}
     if (db_value>300) {digitalWrite(2, HIGH);} else {digitalWrite(2, LOW);}
     if (db_value>350) {digitalWrite(3, HIGH);} else {digitalWrite(3, LOW);}
     if (db_value>400) {digitalWrite(4, HIGH);} else {digitalWrite(4, LOW);}
     if (db_value>500) {digitalWrite(5, HIGH);} else {digitalWrite(5, LOW);}
     if (db_value>600) {digitalWrite(6, HIGH);} else {digitalWrite(6, LOW);}
}

void loop() {
 led();
}
