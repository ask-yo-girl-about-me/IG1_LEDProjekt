 #include <Arduino_MKRENV.h>

void setup() {
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);

  Serial.begin(9600);
    while (!Serial);
  
    if (!ENV.begin()) {
    Serial.println("Failed to initialize MKR ENV shield!");
    while (1);
    }
}

void led() {
 float temperature = ENV.readTemperature();

  // print each of the sensor values
  
  Serial.print("Temperature = ");
  Serial.print(temperature);

  // print an empty line

  Serial.println();

 if (temperature<25)  {digitalWrite(0, HIGH);} else {digitalWrite(0, LOW);}
 if (temperature<27)  {digitalWrite(1, HIGH);} else {digitalWrite(1, LOW);}
 if (temperature<28)  {digitalWrite(2, HIGH);} else {digitalWrite(2, LOW);}
 if (temperature<30) {digitalWrite(3, HIGH);} else {digitalWrite(3, LOW);}
 if (temperature>30) {digitalWrite(4, HIGH);} else {digitalWrite(4, LOW);}
 if (temperature>30) {digitalWrite(5, HIGH);} else {digitalWrite(5, LOW);}
 if (temperature>30) {digitalWrite(6, HIGH);} else {digitalWrite(6, LOW);}
}

void loop() {
 led();
}
