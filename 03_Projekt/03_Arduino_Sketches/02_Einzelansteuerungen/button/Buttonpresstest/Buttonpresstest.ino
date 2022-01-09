unsigned long ZeroMillis = 0;
const unsigned long ButtonPullUPInveral = 25;
byte Count5s = 200;    // 80 * 25 = 2000 ms
byte Count2s = 0;

byte ButtonPullUP = HIGH;         // ButtonPullUP is active low
const byte Button = 8;            // ButtonPullUP is connected to pin 2 and GND

void setup() {
    Serial.begin(115200);
    pinMode(Button, INPUT_PULLUP);
}


void loop() {
    // key management section
    if (millis() - ZeroMillis >= ButtonPullUPInveral) {
        ZeroMillis = millis();
        
        byte currKeyState = digitalRead(Button);
        
        if ((ButtonPullUP == HIGH) && (currKeyState == LOW)) {
            pinMode(0, OUTPUT);
            digitalWrite(0, HIGH);
            delay (1000);
            digitalWrite (0, LOW);
            pinMode(1, OUTPUT);
            digitalWrite(1, HIGH);
            delay (1000);
            digitalWrite (1, LOW);
            pinMode(2, OUTPUT);
            digitalWrite(2, HIGH); 
            delay (1000); 
            digitalWrite (2, LOW);
        }
        else if ((ButtonPullUP == LOW) && (currKeyState == HIGH)) {
                pinMode(3, OUTPUT);
                digitalWrite(3, HIGH);  
                delay (1000);
                digitalWrite (3, LOW);
                pinMode(4, OUTPUT);
                digitalWrite(4, HIGH);  
                delay (1000);
                digitalWrite (4, LOW);
                pinMode(5, OUTPUT);
                digitalWrite(5, HIGH); 
                delay (1000);
                digitalWrite (5, LOW); 
        }
        else if (currKeyState == LOW) {
            Count2s++;
        }
        
        ButtonPullUP = currKeyState;
    }


 

}
