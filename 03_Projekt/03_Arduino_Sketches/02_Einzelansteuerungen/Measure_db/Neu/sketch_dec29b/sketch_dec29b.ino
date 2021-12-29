// test code for Grove - Sound Sensor
// loovee @ 2016-8-30
 
const int pinAdc = A0;
 
void setup()
{
    Serial.begin(115200);
    //Serial.println("Grove - Sound Sensor Test...");
     pinMode(0, OUTPUT);
     pinMode(1, OUTPUT);
     pinMode(2, OUTPUT);
     pinMode(3, OUTPUT);
     pinMode(4, OUTPUT);
     pinMode(5, OUTPUT);
     pinMode(6, OUTPUT);
}
 
void loop()
{
    long sum = 0;
    for(int i=0; i<32; i++)
    {
        sum += analogRead(pinAdc);
    }
    sum >>= 5;
    Serial.println(sum);
    delay(10);
     if (sum>200)  {digitalWrite(0, HIGH);} else {digitalWrite(0, LOW);}
     if (sum>250)  {digitalWrite(1, HIGH);} else {digitalWrite(1, LOW);}
     if (sum>300) {digitalWrite(2, HIGH);} else {digitalWrite(2, LOW);}
     if (sum>350) {digitalWrite(3, HIGH);} else {digitalWrite(3, LOW);}
     if (sum>400) {digitalWrite(4, HIGH);} else {digitalWrite(4, LOW);}
     if (sum>500) {digitalWrite(5, HIGH);} else {digitalWrite(5, LOW);}
     if (sum>600) {digitalWrite(6, HIGH);} else {digitalWrite(6, LOW);}
    
}
