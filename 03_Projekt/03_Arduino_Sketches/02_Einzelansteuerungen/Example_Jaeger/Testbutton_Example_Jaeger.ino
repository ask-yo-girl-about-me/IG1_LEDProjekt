/*
* Aufgabe 7 Read Button then set Output Led
*/

bool onLED = false; // Zustand der LED, zum initialisieren auf false gesetzt
int delayTime = 100; // Verzögerung in ms

void setup() {
pinMode(8, INPUT); // Taster
pinMode(7, OUTPUT); // LED
Serial.begin(9600); // startet den Serial Monitor, mehr dazu später
}

void loop() {
if (digitalRead(8) == LOW) // Abfrage ob der Taster gedrückt ist
{
if (onLED == false) { // ist der Status der LED aus?
onLED = true; // wenn ja, wird er jetzt auf ein gesetzt
}
else {
onLED = false; // wenn der Status der LED ein, wird er jetzt auf aus gesetzt
}
}

if (onLED == true) { // wenn der Status der LED ein ist, wird jetzt der Ausgang auf HIGH geschaltet
digitalWrite(7, HIGH);
}
delay(delayTime); // warte einen Moment
if (onLED == false) { // wenn der Status der LED ais ist, wird jetzt der Ausgang auf LOW geschaltet
digitalWrite(7, LOW);
}
delay(delayTime); // warte einen Moment
}
