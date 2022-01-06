# IG1_LEDProjekt

Dies ist das Projekt von Herr Schmidli und Herr Götzer. In der Ablage finden sie das ganze Projekt und alle dazugehörigen Daten. Die ganze Ablage ist Dokumentiert und beschrieben.

# Inhaltsverzeichnis
- [IG1_LEDProjekt](#ig1_ledprojekt)
- [Inhaltsverzeichnis](#inhaltsverzeichnis)
- [Projekt-Auftrag](#projekt-auftrag)
  - [Lernziele](#lernziele)
  - [Projekt Aufgabe](#projekt-aufgabe)
  - [Abgabe der Projektarbeit](#abgabe-der-projektarbeit)
- [Projekt Beschrieb](#projekt-beschrieb)
- [Analyse](#analyse)
  - [Funktionale Anforderungen](#funktionale-anforderungen)
  - [Nicht-funktionale Anforderungen](#nicht-funktionale-anforderungen)
  - [Signalbeschrieb](#signalbeschrieb)
  - [Blockschaltbild](#blockschaltbild)
- [Design](#design)
  - [Detailschema](#detailschema)
  - [Werte-Zuweisungs-Tabelle](#werte-zuweisungs-tabelle)
  - [Program-Ablauf](#program-ablauf)
  - [Definierte-Testcases](#definierte-testcases)
- [Implementierung](#implementierung)
  - [Realisierung](#realisierung)
  - [Source-Code](#source-code)
  - [>- *Der Source Code ist nachvollziehbar kommentiertVerwendete Quellen sind deklariert*](#--der-source-code-ist-nachvollziehbar-kommentiertverwendete-quellen-sind-deklariert)
- [Testing](#testing)
  - [Durchführung-Testcases](#durchführung-testcases)
- [Road to Goal](#road-to-goal)
  - [Geschichte](#geschichte)
  - [Flashbacks](#flashbacks)
- [Reflexion (Problemstellungen)](#reflexion-problemstellungen)
- [Fazit](#fazit)

---

# Projekt-Auftrag
Der Projekt Auftrag kann grundsätzlich vom Dokument [ITSE21a_IG1_Projektauftrag_Arduino_210908.pdf](https://github.com/ask-yo-girl-about-me/IG1_LEDProjekt/blob/main/01_Allgemein/01_Projektinfos/ITSE21a_IG1_Projektauftrag_Arduino_210908.pdf) entnommen werden. 

Diese Infos wurde aus dem vorhin erwähnten PDF kopiert!

## Lernziele 
- Eine eigene Problemstellung in ein lauffähiges Computer Programm umsetzen können
- Programm-Ablauf der Lösung in geeigneter Form abbilden
- Umrechnung von Signalen in einem Programm richtig umsetzen können
- Einfache Programmbefehle sinnvoll und richtig anwenden können
- Sensoren und Aktoren in einem Microcontroller definieren und in ein Programmablauf einbinden können
- Testcases schreiben und anhand der Testcases die Steuerung überprüfen

## Projekt Aufgabe
In diesem Projekt soll eine einfache Aufgabenstellung mit einem Microcontroller umgesetzt werden. Die Aufgabenstellung kann selber definiert werden. Die Aufgabenstellung soll folgende minimale Anforderungen erfüllen:

- Das System muss digitale und analoge Ein- und Ausgänge verwenden
- Das System soll eine praxisnahe Aufgabenstellung lösen
- Die Realisierung der Aufgabenstellung wird selbständig umgesetzt und kann erklärt werden
- Die Implementierung soll mit einem ARDUINO Microcontroller (Z.B. MKR1010 oder ähnlich),umgesetzt werden

## Abgabe der Projektarbeit
|Was|Beschreibung|
|--------|--------|
|    Dokumentation    |    Vollständige PDF-Dokumentation    |
|    Source Code    |    Source Code und Libraries (Arduino Sketch) als ZIP File    |
|    Abgabe Format    |    Das gesamte Projekt wird als ZIP File abgegeben    |
|    Namenskonvention    |    Nachname01_Nachname02_ITSE21a_Projektauftrag.ZIP    |
|    Abgabeort    |    Teams…\Kursmaterialien\04_Abgaben    |
|    Abgabe Dokumentation    |    23.01.22    |
|    Schluss-Präsentation    |    27.01.22 oder 03.02.22    |

---

# Projekt Beschrieb
Der Projekt Beschrieb, basiert auf dem Projekt Antrag. Der Projektbeschrieb wurde durch Herr Schmidli und Herr Götzer erstellt. Dieser wurde durch Herr Jäger abgesegnet und somit per PDF festgehalten. 

Das Original ist hier zu finden: [Goetzer_Schmidli_ITSE21a_IG1_Projektantrag_V2.pdf](https://github.com/ask-yo-girl-about-me/IG1_LEDProjekt/blob/main/02_Documents/01_Projektbezogenes/Goetzer_Schmidli_ITSE21a_IG1_Projektantrag_V2.pdf)

Am 04.11.2021 wurde eine zweite Version des Projekt Beschriebs erstellt. Dies wurde aus dem Grund gemacht, da wir Probleme hatten mit der LED Hardware. Somit haben wir den Projektantrag minim angepasst um das Problem mit den LED Stripes zu umgehen.

Hier den definierten Projekt Beschrieb vom [Projektantrag V2](https://github.com/ask-yo-girl-about-me/IG1_LEDProjekt/blob/main/02_Documents/01_Projektbezogenes/Goetzer_Schmidli_ITSE21a_IG1_Projektantrag_V2.pdf):

In unserem Projekt handelt es sich um zwei integrierte Programme mit LEDs. Per Druck-Knopf wechseln wir durch die verschiedenen Programme durch. Programm eins handelt sich um die aktuelle Temperatur, welche durch Ändern der Farbe auf den LEDs angezeigt wird. Programm zwei handelt sich um einen DB Meter. Das Programm startet mit deaktivierten LEDs. Sobald Ton erkannt wird, werden die LEDs gemäss DB von unten nach oben aktiviert. Dies wird zusätzlich noch mit Farbe (Rote, grüne und Gelbe LEDs) gekennzeichnet.
Der Programmwechsel durch den Knopf wird mittels Blinkens von grünen LEDs angezeigt. Programm eins blinkt einmal für eine definierte Zeit. Programm zwei blinkt zwei Mal für eine definierte Zeit.

Optional wenn noch Zeit zur Verfügung ist:
- Messwerte auf eine SD-Karte Protokollieren

Erforderliche Hardware für Projekt:
- MKR Wifi 1010
- MKR ENV Shield (Thermometer)
- Mikrophon (DB Messer)
- SD-Karte
- 2 Grüne LED
- 2 Gelbe LED
- 2 Rote LED
- Druck-Knopf

---

# Analyse
Hier bei der Analyse werden alle nötigen Infos definiert aufgezeigt, welche man für die Realisation braucht.

## Funktionale Anforderungen

---
**Lernziel 1_Analyse 1**

>- *"Es gibt eine vollständige Liste mit den funktionalen Anforderungen und diese sind umfassend beschrieben (SMART)"*

---

- Das Programm kann anhand von grünen, gelben und roten LEDs die lautstärke anzeigen. Es fangt mit grün an und je lauter es wieder je mehr LEDs werden aktiv und es wechselt von grün auf gelb und am schluss noch rot.

- Der Temperaturmeter zeigt die anhand von grünen, gelben und roten LEDs die Optimale Temperatur an. 25°-27° ist grün, 28°-30° ist gelb und alles über 30° ist rot.

- Die Dezibel und Temperatur Daten werden geloggt und in eine CSV Datei auf die internen SD Karte geschrieben.

- Per Knopfdruck kann man von einen ersten programm in das zweite wechseln.

## Nicht-funktionale Anforderungen

---
**Lernziel 1_Analyse 1.1**

>- *"Es gibt eine Liste mit den nicht-funktionalen Anforderungen"*

---

- Die Temperaturmessung kann Temperaturen von -40 °C und +120 °C aufnehmen. Der Bereich im Programm ist auf 15° bis 30 ° definiert.
  
- Das Progamm kann mindestens 5 Minuten laufen ohne ausfall (Überhitzen oder Aussetzer)
  
-  Die jeweiligen Daten werden sobald das jeweilige Programm (entweder DB-Meter oder Temp-Meter) geloggt solange bis das Programm gewechselt wird, SD Karte ausgesteckt wird oder der Arduino beendet wird.
  
## Signalbeschrieb

---
**Lernziel 1_Analyse 2**

>- *Sämtiche Signale an den Ein- und Ausgängen sind vollständig beschrieben: Signalart, Wertebereich, Umwandlungen*

---

**Schalter am Eingang**

- Signalart: Gleichspannung
- Wertebereich: 0 V oder 3.3 V
- Umwandlung: 0 V entspricht keiner Funktion und 3.3 V entspricht change case
 
**Mikrofon am Eingang**

- Signalart: Wechselspannung (das Mik wandelt Schalldruck in Wechselspannung um)
- Wertebereich: zwischen 0 V und 3.3 V sind alle Werte möglich
- Umwandlung: z.B. 70 dB SPL entsprechen 1.2 V AC und bedeutet im Programm, dass die grüne LED leuchtet

**LED am Ausgang**

- Signalart: Gleichspannung
- Wertebereich: zwischen 0 und 3.3 V
- Umwandlung: 0 V LED deaktiviert 3.3 V LED aktiv

## Blockschaltbild

---
**Lernziel 1_Analyse 3**

>- *"Es liegt ein vollständiges Blockschaltbild (Übersichtsschema) vor"*
>- *"Saubere und übersichtliche Darstellung: keine oder wenig Kreuzungen, nur horizontale oder vertikale Linien, Beschriftung sämtlicher Elemente"*

---

![Blockschaltbild](../00_img/Projekt/blockschaltbild.jpeg)

---

# Design


## Detailschema

---
**Lernziel 2_Design 1**

>- *"Es liegt ein vollständiges Detailschema des Prototypen mit Pingranularität vor, d.h. jeder einzelne Pin ist ersichtlich"*
>- *"Saubere und übersichtliche Darstellung: keine oder wenig Kreuzungen, nur horizontale oder vertikale Linien, Beschriftung sämtlicher Elemente"*

---

Hier finden sie den Link zur TinkerCAD Seite wo das Blockschaltbild erstellt wurde. Dieses unten noch als Bild aufgezeigt.

[TinkerCAD](https://www.tinkercad.com/things/7osfcFXCBFJ)

![TinkerCAD](https://github.com/ask-yo-girl-about-me/IG1_LEDProjekt/blob/main/03_Projekt/02_TinkerCAD/IG1_LEDProjekt.png)

## Werte-Zuweisungs-Tabelle

---
**Lernziel 2_Design 2**

>- *"Die Verknüpfungen (Logik) der Ein- und Ausgangssignale sind vollständig beschrieben"*

---

|  PIN  |  -  |  -  |  -  |
|--------|--------|--------|--------|
|  AREF  |    |    |    |
|  A0 |    |    |    |
|  A1 |    |    |    |
|  A2 |    |    |    |
|  A3 |    |    |    |
|  A4 |    |    |    |
|  A5 |    |    |    |
|  A6 |    |    |    |
|  D0   |    |    |    |
|  D1   |    |    |    |
|  D2   |    |    |    |
|  D3   |    |    |    |
|  D4   |    |    |    |
|  D5   |    |    |    |
|  D6   |    |    |    |
|  D7   |    |    |    |
|  D8   |    |    |    |
|  D9   |    |    |    |
|  D10   |    |    |    |
|  D11   |    |    |    |
|  D12   |    |    |    |
|  D13   |    |    |    |
|  D14   |    |    |    |
|  RESET   |    |    |    |
|  GND   |    |    |    |
|  +3V3   |    |    |    |
|  VIN   |    |    |    |
|  +5V   |    |    |    |


## Program-Ablauf

---
**Lernziel 2_Design 3**

>- *"Der Programmablauf ist mit einer geeigneten Darstellungsmethode (Struktogramm, Flussdiagramm, Statemachine, …) vollständig beschrieben*
>- *"Der Programmablauf ist sauber gezeichnet""*

---

Die Datenablage für den Programm-Ablaufen finden Sie hier: [Ablage Programm-Ablauf](https://github.com/ask-yo-girl-about-me/IG1_LEDProjekt/tree/main/03_Projekt/01_Structorizer)

![Struktogramm](https://github.com/ask-yo-girl-about-me/IG1_LEDProjekt/blob/main/03_Projekt/01_Structorizer/IG1_Structorizer.png)

## Definierte-Testcases

---
**Lernziel 2_Design 4**

>- *"Es liegt eine Liste mit sämtlichen Testcases, basierend auf den funktionalen und nicht-funktionalen Anforderungen, vor"*

---

Testgruppen

|  Nr.  |  Thema  |  Was?  |
|--------|--------|--------|
|  TG-10  |  Dezibel Meter  |  Der Dezibel Meter wird auf seine funktionalitäten gemäss Funktionalen und nicht-funktionalen Anforderungen überprüft  |
|  TG-20  |  Temperatur Meter  |  Der Temperatur Meter wird auf seine funktionalitäten gemäss Funktionalen und nicht-funktionalen Anforderungen überprüft  |
|  TG-30  |  Change Case  |  Der Case Change wird auf seine funktionalitäten gemäss Funktionalen und nicht-funktionalen Anforderungen überprüft  |
|  TG-40  |  SD Loggin  |  Das loggen auf die SD Karte wird auf seine funktionalitäten gemäss Funktionalen und nicht-funktionalen Anforderungen überprüft  |

**TG-10**
|  Nr.  |  Was  |  Wie  |  Erwartetes Resultat  |
|--------|--------|--------|--------|
|  10-1  |  Grüne LEDS  |  Song auf Handy laufen lassen mit 10% lautstärke. | Nur die grüne LEDs sind |
|  10-2  |  Gelben LEDS  |  Song auf Handy laufen lassen mit 50% lautstärke. | Die grünen und gelben LEDs sind aktiv |
|  10-3  |  Roten LEDS  |  Song auf Handy laufen lassen mit 100% lautstärke. | Die grünen, gelben und roten LEDs sind aktiv |
|  10-4  |  Kein Microfon  |  Microfon wird entfernt  |  Keine LEDs sind aktiv | 

**TG-20**
|  Nr.  |  Was  |  Wie  |  Erwartetes Resultat  |
|--------|--------|--------|--------|
|  20-1  |  Grüne LEDs  |  Temperatur auf 25°-27° regulieren | Nur die grüne LEDs sind aktiv |
|  20-2  |  Gelbe LEDs  |  Temperatur auf 28°-30° regulieren | Die grüne und gelben LEDs sind aktiv |
|  20-3  |  Roten LEDs  |  Temperatur auf 31° und mehr regulieren | Die grüne. gelben und roten LEDs sind aktiv |

**TG-30**
|  Nr.  |  Was  |  Wie  |  Erwartetes Resultat  |
|--------|--------|--------|--------|
|  30-1  |  In das erste Programm wechseln  | Nach dem Programm Start Knopf ein Mal drücken  | 1 Case läuft durch (DB meter) |
|  30-2  | In das zweite Programm wechseln   | Nach dem Programm Start Knopf zwei Mal drücken und wenn man im Case 1 ist nur einmal | 2 Case läuft durch (DB meter)
|  30-3  |  Überschreiten der Case Nummer  | Knopf mehr als 2 mal drücken  | Da wir nur 2 Cases haben,ist beim 3 mal drücken das Programm fertig |

**TG-40**
|  Nr.  |  Was  |  Wie  |  Erwartetes Resultat  |
|--------|--------|--------|--------|
|  40-1  |  Dezibel Daten werden geloggt  |  Das ganze per SD Karte und dem Microfon. SD Karte nach durchlaufen des Programms entfernen und an einen PC/Laptopn anschliesen  | Ein CSV File mit den Daten enthalten. Zuoberst ein Titel mit beschriftung Dezibel-Value. |
|  40-2  |  Temperatur Daten werden geloggt  | Das ganze per SD Karte und dem ENV Shield. SD Karte nach durchlaufen des Programms entfernen und an einen PC/Laptopn anschliesen  | Ein CSV File mit den Temperatur Date enthalte. Zuoberst ein Titel mit beschriftung Temperatur-Value.  |
|  40-3  |  SD Karte entfernen  | SD Karte währen dem laufen des Programms entfernen  | Daten sind auf in CSV enthalten |
|  40-4  |  Keine SD Karte  | Das Programm ohne SD Karte starten  | Meldung im Serial Monitor, dass keien SD Karte vorhanden ist. |

---

# Implementierung


## Realisierung

---
**Lernziel 3_Implementierung 1**

>- *Schwirigkeitsgrad*
> *0: einfach, von Vorlage kopiert*
> *1: einfach, leicht modifiziert und erweitert*
> *2: anspruchsvoll*
> *3: komplex*
>- *Sämtliche funktionalen und nicht-funktionalen Anforderungen werden erfüllt und können demonstriert werden*
>- *Zweckmässiger, robuster Aufbau*

---


## Source-Code

---
**Lernziel 3_Implementierung 2-3**

>- *Schwirigkeitsgrad*
> *0: einfach, kopiert von einem HelloWord Beispiel*
> *1: einfach, leicht modifiziert und erweitert*
> *2: mittelschwer (Funktionen, Variablen, Iterationen, Verzweigungen, …)*
> *3: anspruchsvoll (Register, Interrupts, Umrechnungen, ...)*
> *4: komplex (json, State Machine, Arrays, ...)*
>- *Der eigene Code kann Zeile für Zeile erklärt werden*
>- *Der Source Code ist nachvollziehbar kommentiertVerwendete Quellen sind deklariert*
---

---

# Testing

---
**Lernziel 4_Testing 1-2**

>- *Es liegt eine Liste mit Testcases vor, welche auf den funktionalen und nicht-funktionalen Anforderungen basiert*
>- *Die Testcases sind durchgeführt und die Resultate liegen vor*
>- *Es liegt eine Tabelle mit folgenden Spalten vor: Nummer, Beschreibung, erwartete Reaktion, Ergebnis, Status*
>- *Sämtliche Testcases sind in einer Tabelle dokumentiert*

---

## Durchführung-Testcases

Testgruppen

|  Nr.  |  Thema  |  Was?  |  Resultat  |
|--------|--------|--------|--------|
|  TG-10  |  Dezibel Meter  |  Der Dezibel Meter wird auf seine funktionalitäten gemäss Funktionalen und nicht-funktionalen Anforderungen überprüft  |  |
|  TG-20  |  Temperatur Meter  |  Der Temperatur Meter wird auf seine funktionalitäten gemäss Funktionalen und nicht-funktionalen Anforderungen überprüft  |   |
|  TG-30  |  Change Case  |  Der Case Change wird auf seine funktionalitäten gemäss Funktionalen und nicht-funktionalen Anforderungen überprüft  |    |
|  TG-40  |  SD Loggin  |  Das loggen auf die SD Karte wird auf seine funktionalitäten gemäss Funktionalen und nicht-funktionalen Anforderungen überprüft  |   |

**TG-10**
|  Nr.  |  Was  |  Wie  |  Erwartetes Resultat  | Resultat |
|--------|--------|--------|--------|--------|
|  10-1  |  Grüne LEDS  |  Song auf Handy laufen lassen mit 10% lautstärke. | Nur die grüne LEDs sind |   |
|  10-2  |  Gelben LEDS  |  Song auf Handy laufen lassen mit 50% lautstärke. | Die grünen und gelben LEDs sind aktiv |   |
|  10-3  |  Roten LEDS  |  Song auf Handy laufen lassen mit 100% lautstärke. | Die grünen, gelben und roten LEDs sind aktiv | |
|  10-4  |  Kein Microfon  |  Microfon wird entfernt  |  Keine LEDs sind aktiv |  |

**TG-20**
|  Nr.  |  Was  |  Wie  |  Erwartetes Resultat  | Resultat |
|--------|--------|--------|--------|--------|
|  20-1  |  Grüne LEDs  |  Temperatur auf 25°-27° regulieren | Nur die grüne LEDs sind aktiv | |
|  20-2  |  Gelbe LEDs  |  Temperatur auf 28°-30° regulieren | Die grüne und gelben LEDs sind aktiv | |
|  20-3  |  Roten LEDs  |  Temperatur auf 31° und mehr regulieren | Die grüne. gelben und roten LEDs sind aktiv | |

**TG-30**
|  Nr.  |  Was  |  Wie  |  Erwartetes Resultat  | Resultat |
|--------|--------|--------|--------|--------|
|  30-1  |  In das erste Programm wechseln  | Nach dem Programm Start Knopf ein Mal drücken  | 1 Case läuft durch (DB meter) | |
|  30-2  | In das zweite Programm wechseln   | Nach dem Programm Start Knopf zwei Mal drücken und wenn man im Case 1 ist nur einmal | 2 Case läuft durch (DB meter)|  |
|  30-3  |  Überschreiten der Case Nummer  | Knopf mehr als 2 mal drücken  | Da wir nur 2 Cases haben,ist beim 3 mal drücken das Programm fertig |  |

**TG-40**
|  Nr.  |  Was  |  Wie  |  Erwartetes Resultat  | Resultat  |
|--------|--------|--------|--------|--------|
|  40-1  |  Dezibel Daten werden geloggt  |  Das ganze per SD Karte und dem Microfon. SD Karte nach durchlaufen des Programms entfernen und an einen PC/Laptopn anschliesen  | Ein CSV File mit den Daten enthalten. Zuoberst ein Titel mit beschriftung Dezibel-Value. |  |
|  40-2  |  Temperatur Daten werden geloggt  | Das ganze per SD Karte und dem ENV Shield. SD Karte nach durchlaufen des Programms entfernen und an einen PC/Laptopn anschliesen  | Ein CSV File mit den Temperatur Date enthalte. Zuoberst ein Titel mit beschriftung Temperatur-Value.  |  |
|  40-3  |  SD Karte entfernen  | SD Karte währen dem laufen des Programms entfernen  | Daten sind auf in CSV enthalten |  |
|  40-4  |  Keine SD Karte  | Das Programm ohne SD Karte starten  | Meldung im Serial Monitor, dass keien SD Karte vorhanden ist. |  |

---

# Road to Goal

## Geschichte

Als erstes haben wir mal Ideen gesammelt, was wir als Projekt machen können. Im Internet haben wir gesehen, dass man mit dem Arduino LEDs ansteuern kann mit LED Streifen. Somit haben wir dies als Grundbau genommen und sind mit der Idee gekommn einen mit LED Streifen einen Dezibel und Temperatur Meter zu machen. Leider mussten wir dies dann aber durch gewisse Progleme durch einzelne LEDs wechseln. 

Nach dem wir unser Projekt beschrieb fertig hatten, machten wir uns an das Detail-Schema und das Struktogramm. Somit haben wir im TinkerCAD das Detail-Schema so aufgebaut wie wir uns das vorgestellt haben und es so dann auch einfacher haben in echt aufzubauen. Das Struktogramm haben wir per Structorizer gezeichnet und haben uns so schon mal einen grundbau für das Programm erstellt.

Nun ist das Grundfundament aufgebaut und alles ist bereit für das Programmierne. Somit machten wir uns an die ansteuerung der einzelnen Geräten.

1. Einzelne LED ansteuern [Link](https://github.com/ask-yo-girl-about-me/IG1_LEDProjekt/blob/main/03_Projekt/03_Arduino_Sketches/02_Einzelansteuerungen/LED-Einzeln/LED-Einzeln.ino)
2. LED Testing [Link](https://github.com/ask-yo-girl-about-me/IG1_LEDProjekt/blob/main/03_Projekt/03_Arduino_Sketches/02_Einzelansteuerungen/LED-Testing/LED-Testing.ino)
3. Button funktionalität [Link](https://github.com/ask-yo-girl-about-me/IG1_LEDProjekt/blob/main/03_Projekt/03_Arduino_Sketches/02_Einzelansteuerungen/button/button.ino)
4. Switch Case mit Button [Link](https://github.com/ask-yo-girl-about-me/IG1_LEDProjekt/blob/main/03_Projekt/03_Arduino_Sketches/02_Einzelansteuerungen/switchcase_button/switchcase_button.ino)
5. Dezibel auslesen in Seriel Monitor [Link](https://github.com/ask-yo-girl-about-me/IG1_LEDProjekt/blob/main/03_Projekt/03_Arduino_Sketches/02_Einzelansteuerungen/Measure_DB/Measure_DB.ino)
6. Temperatur auslesen in Seriel Monitor [Link](https://github.com/ask-yo-girl-about-me/IG1_LEDProjekt/blob/main/03_Projekt/03_Arduino_Sketches/02_Einzelansteuerungen/Measure_Temperature/Measure_Temperature.ino) 
7. ENV Shield Infos auf SD Karte schreiben [Link](https://github.com/ask-yo-girl-about-me/IG1_LEDProjekt/blob/main/03_Projekt/03_Arduino_Sketches/02_Einzelansteuerungen/SD_Writer/store_data_in_memory_card_envshield/store_data_in_memory_card_envshield.ino)
8. DB Meter Infos auf SD karte schreiben [Link](https://github.com/ask-yo-girl-about-me/IG1_LEDProjekt/blob/main/03_Projekt/03_Arduino_Sketches/02_Einzelansteuerungen/SD_Writer/db_SD/db_SD.ino)
9. Dezibel Meter [Link](https://github.com/ask-yo-girl-about-me/IG1_LEDProjekt/blob/main/03_Projekt/03_Arduino_Sketches/02_Einzelansteuerungen/LED_DBMeter/LED_DBMeter.ino)
10. Temperatur Meter [Link](https://github.com/ask-yo-girl-about-me/IG1_LEDProjekt/blob/main/03_Projekt/03_Arduino_Sketches/02_Einzelansteuerungen/LED-TempMeter/LED-TempMeter.ino)

Sobald wir alle einzelnen Ansteuerungen hatten, machten wir uns an das Zusammenführen aller Programme, damit diese in einem einzenlnen Programm tangiert.

## Flashbacks

Hier werden einige Flashbacks aufgezeigt, welche eine Wichtige Rolle in dem ganzen Projekt gespielt haben. 
Die anten kann man sogar als Milestones anschauen.

**Flashback 1**

Das erste mal den Arduino auf der Steckerplatine mit den LEDs verbunden. Dies war das erste erfolgserlebniss von uns beiden. Wir natürlich zuerst die LEDs einmal austesten und schauen wie diese funktionieren.

![Flashback1](https://github.com/ask-yo-girl-about-me/IG1_LEDProjekt/blob/main/00_img/Flashbacks/1.jpg)

**Flashback 2**



![Flashback2](https://github.com/ask-yo-girl-about-me/IG1_LEDProjekt/blob/main/00_img/Flashbacks/2.jpg)

**Flashback 3**



![Flashback3](https://github.com/ask-yo-girl-about-me/IG1_LEDProjekt/blob/main/00_img/Flashbacks/3.0.jpg)

![Flashback3.1](https://github.com/ask-yo-girl-about-me/IG1_LEDProjekt/blob/main/00_img/Flashbacks/3.1.jpg)

![Flashback3.2](https://github.com/ask-yo-girl-about-me/IG1_LEDProjekt/blob/main/00_img/Flashbacks/3.2.jpg)

**Flashback 4**



[Video DB Meter](https://github.com/ask-yo-girl-about-me/IG1_LEDProjekt/blob/main/00_img/Flashbacks/4.mp4)



---

# Reflexion (Problemstellungen)
- Hardware (LED Streifen/ENV Shield)
- Programmsprache C
- FastLED Library welche nur ging wenn man MKR1000 ausgewählt hat
- Haupprogramm Struktur SwitchCase (Technisch nicht möglich)

---

# Fazit


>«Wir erklären hiermit, dass wir diese Arbeit selbständig verfasst und keine anderen als die angegebenen Quellen benutzt haben. Alle Stellen, die wörtlich oder sinngemäss aus Quellen entnommen wurden, haben wir als solche gekennzeichnet.»

[^1]:
[^2]:
[^3]:
[^4]:
[^5]:
[^6]:
[^7]: