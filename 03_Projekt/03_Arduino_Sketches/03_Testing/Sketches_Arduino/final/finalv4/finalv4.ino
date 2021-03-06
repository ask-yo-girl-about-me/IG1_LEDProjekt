#include <Arduino_MKRENV.h>
#include <SPI.h>
#include <SD.h>
#define MIC A0

// Button Pin definieren
const int button = 8;     

// Chip Auswahl für PIN 4
const int SD_CS_PIN = 4;  

// Variabel Definitionen //
// CountButton
int buttonState = 0;         
int count_value = 0;
int prestate = 0;
int ledblink = 1;
// Temp Meter
float temperature = 0;
// DB Meter
int adc;
int dB, PdB; 

// File Objekt für Log auf SD Karte
File dataFile_temp;
File dataFile_dB;

void setup() {
    // Inizialisieren des Buttons PIN als Input
    pinMode(button, INPUT_PULLUP);
    // Inizialisieren die LED PINs als Output      
    pinMode(0, OUTPUT);
    pinMode(1, OUTPUT);
    pinMode(2, OUTPUT);
    pinMode(3, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(A1, OUTPUT);
  
    Serial.begin(9600);
    while (!Serial);
    
    // init das ENV Shield
    if (!ENV.begin()) {
        // Wenn das ENV Shield nicht inizialisiert werden kann, kommt diese Meldung
        Serial.println("Failed to initialize MKR ENV shield!");
        while (1);
    }

    // init SPI
    SPI.begin();
    delay(100);

    // init die SD card
    if(!SD.begin(SD_CS_PIN)) {
        // Wenn die SD Karte nicht inizialisiert werden kann, kommt diese Meldung
        Serial.println("Failed to initialize SD card!");
        while (1);
    }

    // init das logfile
    // Log File für die Temperatur
    dataFile_temp = SD.open("log-0001.csv", FILE_WRITE);
    delay(1000);
    // Log File für den dB
    dataFile_dB = SD.open("log-0002.csv", FILE_WRITE);

    // init the CSV file with headers
    dataFile_temp.println("temperature");
    dataFile_dB.println("dB");

    // close the file
    dataFile_temp.close();
    delay(100);
    dataFile_dB.close();
}

void loop() {
    // pushbutto Wert auslesen
    buttonState = digitalRead(button);

    // Kontrollieren ob der pushbutton gedrückt ist. Wenn ja, dann ist der buttonState HIGH
    if (buttonState == LOW && prestate == 0) {
        count_value++;
        Serial.print(count_value);
        delay(100);
        prestate = 1;
    }else if(buttonState == HIGH){
        prestate = 0;
    }

    // Temperatur Meter //
    if (count_value == 1){
        // Erstes Programm wird hier mit ein Mal blinken der Blauen LED angezeigt
        if (ledblink == 1){
            digitalWrite(A1, HIGH);
            delay(1000);
            digitalWrite(A1, LOW);
            ledblink = 2;
        }

        // Lesen der Temperatur Werte
        float temperature = ENV.readTemperature();

        // Gibt die Temperatur Werte im Serial Monitor aus
        Serial.print("Temp Meter = ");
        Serial.print(temperature);
       
        // Hier passiert der ganze Zauber, welche LED aktiv sein muss oder eben nicht
        Serial.println();
        // Blaue LED HIGH wenn unter 19.99° ansonsten LOW
        if (temperature<19.99) {digitalWrite(A1, HIGH);} else {digitalWrite(A1, LOW);}
        // 1 Grüne LED HIGH wenn über 20° ansonsten LOW
        if (temperature>20.00) {digitalWrite(0, HIGH);} else {digitalWrite(0, LOW);}
        // 2 Grüne LED HIGH wenn über 25° ansonsten LOW
        if (temperature>25.00) {digitalWrite(1, HIGH);} else {digitalWrite(1, LOW);}
        // 1 Gelbe LED HIGH wenn über 27° ansonsten LOW
        if (temperature>27.00) {digitalWrite(2, HIGH);} else {digitalWrite(2, LOW);}
        // 2 Gelbe LED HIGH wenn über 29° ansonsten LOW
        if (temperature>29.00) {digitalWrite(3, HIGH);} else {digitalWrite(3, LOW);}
        // 1 Rote LED HIGH wenn über 31° ansonsten LOW
        if (temperature>31.00) {digitalWrite(5, HIGH);} else {digitalWrite(5, LOW);}
        // 2 Rote LED HIGH wenn über 35° ansonsten LOW
        if (temperature>35.00) {digitalWrite(6, HIGH);} else {digitalWrite(6, LOW);}
        buttonState;
    }

    // Log Temperatur //
    if (count_value == 2){
        if (ledblink == 2){
            // Zweites Programm wird hier mit zwei Mal blinken der Blauen LED angezeigt
            digitalWrite(A1, HIGH);
            delay(1000);
            digitalWrite(A1, LOW);
            delay(1000);
            digitalWrite(A1, HIGH);
            delay(1000);
            digitalWrite(A1, LOW);
            ledblink = 3;
        }
        // init das logfile
        dataFile_temp = SD.open("log-0001.csv", FILE_WRITE);
        delay(1000);
      
        // Lesen der Temperatur Werte
        float temperature = ENV.readTemperature();
      
        // Gibt die Temperatur Werte im Serial Monitor aus
        Serial.print("Temp Log = ");
        Serial.println(temperature);
      
        // Gibt die Temperatur Werte in das logfile
        dataFile_temp.print(temperature);
        // Schliesst das Logfile
        dataFile_temp.close();
        // Wartet eine Sekunde bis zur nächster Ausgabe
        delay(1000);
        buttonState;
    }

    // Dezibel Meter //
    if (count_value == 3){
        if (ledblink == 3){
            // Drittes Programm wird hier mit drei Mal blinken der Blauen LED angezeigt
            digitalWrite(A1, HIGH);
            delay(1000);
            digitalWrite(A1, LOW);
            delay(1000);
            digitalWrite(A1, HIGH);
            delay(1000);
            digitalWrite(A1, LOW);
            delay(1000);
            digitalWrite(A1, HIGH);
            delay(1000);
            digitalWrite(A1, LOW);
            delay(1000);
            ledblink = 4;
        }   

        // Lesen der Dezibel Werte
        //ADC Werte lesen vom Verstärker
        adc= analogRead(MIC); 
        // Konvertieren der ADC Werte in dB anhand von Regression Werten
        dB = (adc+83.2073) / 11.003;
        // Gibt im Serial Monitor die db Werte aus
        Serial.print("dB Meter = ");
        Serial.println(dB);

        // Hier passiert der ganze Zauber, welche LED aktiv sein muss oder eben nicht
        Serial.println();
        // 1 Grüne LED HIGH wenn über 50dB ansonsten LOW
        if (dB>50) {digitalWrite(0, HIGH);} else {digitalWrite(0, LOW);}
        // 2 Grüne LED HIGH wenn über 60dB ansonsten LOW
        if (dB>60) {digitalWrite(1, HIGH);} else {digitalWrite(1, LOW);}
        // 1 Grüne LED HIGH wenn über 70dB ansonsten LOW
        if (dB>70) {digitalWrite(2, HIGH);} else {digitalWrite(2, LOW);}
        // 1 Grüne LED HIGH wenn über 80dB ansonsten LOW
        if (dB>80) {digitalWrite(3, HIGH);} else {digitalWrite(3, LOW);}
        // 1 Grüne LED HIGH wenn über 90dB ansonsten LOW
        if (dB>90) {digitalWrite(5, HIGH);} else {digitalWrite(5, LOW);}
        // 1 Grüne LED HIGH wenn über 100dB ansonsten LOW
        if (dB>100) {digitalWrite(6, HIGH);} else {digitalWrite(6, LOW);}
        buttonState;
    }
  
    // Log Dezibel
    if (count_value == 4){
        if (ledblink == 4){
            // Viertes Programm wird hier mit vier Mal blinken der Blauen LED angezeigt
            digitalWrite(A1, HIGH);
            delay(1000);
            digitalWrite(A1, LOW);
            delay(1000);
            digitalWrite(A1, HIGH);
            delay(1000);
            digitalWrite(A1, LOW);
            delay(1000);
            digitalWrite(A1, HIGH);
            delay(1000);
            digitalWrite(A1, LOW);
            delay(1000);
            digitalWrite(A1, HIGH);
            delay(1000);
            digitalWrite(A1, LOW);
            delay(1000);
            ledblink = 5;
        }
        // init das logfile
        dataFile_dB = SD.open("log-0002.csv", FILE_WRITE);
        delay(1000);
        
        // Lesen der Dezibel Werte
        //ADC Werte lesen vom Verstärker
        adc= analogRead(MIC); 
        // Konvertieren der ADC Werte in dB anhand von Regression Werten
        dB = (adc+83.2073) / 11.003;
        // Gibt im Serial Monitor die db Werte aus
        Serial.print("dB Log = ");
        Serial.println(dB);

        // Gibt die Temperatur Werte in das logfile
        dataFile_dB.print(dB);
        // Schliess das logfile
        dataFile_dB.close();
        // Wartet eine Sekunde bis zur nächster Ausgabe
        delay(1000);
        
        buttonState;
    }
    
    // Programm 5 bei dem nichts mehr passiert und der Count wieder auf 0 gesezt wird, somit kann man das ganze wieder von Programm eins nutzen
    if (count_value == 5){
        count_value =0;
        buttonState;
    }
}
