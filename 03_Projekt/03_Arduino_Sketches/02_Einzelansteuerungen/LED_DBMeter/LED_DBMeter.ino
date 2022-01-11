#define MIC A0
int adc;
int dB, PdB; //the variable that will hold the value read from the microphone each time


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

     
void loop() {
    adc= analogRead(MIC); //Read the ADC value from amplifer 
    Serial.println (adc);//Print ADC for initial calculation 
    dB = (adc+83.2073) / 11.003; //Convert ADC value to dB using Regression values

     if (dB>50) {digitalWrite(0, HIGH);} else {digitalWrite(0, LOW);}
     if (dB>60) {digitalWrite(1, HIGH);} else {digitalWrite(1, LOW);}
     if (dB>70) {digitalWrite(2, HIGH);} else {digitalWrite(2, LOW);}
     if (dB>80) {digitalWrite(3, HIGH);} else {digitalWrite(3, LOW);}
     if (dB>90) {digitalWrite(4, HIGH);} else {digitalWrite(4, LOW);}
     if (dB>100) {digitalWrite(5, HIGH);} else {digitalWrite(5, LOW);}
     
}
