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

>*"Es gibt eine vollständige Liste mit den funktionalen Anforderungen und diese sind umfassend beschrieben (SMART)"*

---

- Das Programm kann anhand von grünen, gelben und roten LEDs die lautstärke anzeigen. Es fangt mit grün an und je lauter es wieder je mehr LEDs werden aktiv und es wechselt von grün auf gelb und am schluss noch rot.

- Der Temperaturmeter zeigt die anhand von grünen, gelben und roten LEDs die Optimale Temperatur an. 25°-27° ist grün, 28°-30° ist gelb und alles über 30° ist rot.

- Die Dezibel und Temperatur Daten werden geloggt und in eine CSV Datei auf die internen SD Karte geschrieben.

- Per Knopfdruck kann man von einen ersten programm in das zweite wechseln.

## Nicht-funktionale Anforderungen

---
**Lernziel 1_Analyse 1.1**

>*"Es gibt eine Liste mit den nicht-funktionalen Anforderungen"*

---

- Die Temperaturmessung kann Temperaturen von -40 °C und +120 °C aufnehmen. Der Bereich im Programm ist auf 15° bis 30 ° definiert.
  
- Das Progamm kann mindestens 5 Minuten laufen ohne ausfall (Überhitzen oder Aussetzer)
  
-  Die jeweiligen Daten werden sobald das jeweilige Programm (entweder DB-Meter oder Temp-Meter) geloggt solange bis das Programm gewechselt wird, SD Karte ausgesteckt wird oder der Arduino beendet wird.
  
## Signalbeschrieb

---
**Lernziel 1_Analyse 2**

>*Sämtiche Signale an den Ein- und Ausgängen sind vollständig beschrieben: Signalart, Wertebereich, Umwandlungen*

---

**Schalter am Eingang**
Signalart: Gleichspannung
Wertebereich: 0 V oder 3.3 V
Umwandlung: 0 V entspricht keiner Funktion und 3.3 V entspricht change case
 
**Mikrofon am Eingang**
Signalart: Wechselspannung (das Mik wandelt Schalldruck in Wechselspannung um)
Wertebereich: zwischen 0 V und 3.3 V sind alle Werte möglich
Umwandlung: z.B. 70 dB SPL entsprechen 1.2 V AC und bedeutet im Programm, dass die grüne LED leuchtet

**LED am Ausgang**
Signalart: Gleichspannung
Wertebereich: zwischen 0 und 3.3 V
Umwandlung: 0 V LED deaktiviert 3.3 V LED aktiv


## Blockschaltbild

---
**Lernziel 1_Analyse 3**

>*"Es liegt ein vollständiges Blockschaltbild (Übersichtsschema) vor"*
>*"Saubere und übersichtliche Darstellung: keine oder wenig Kreuzungen, nur horizontale oder vertikale Linien, Beschriftung sämtlicher Elemente"*

---

---

# Design


## Detailschema

---
**Lernziel 2_Design 1**

>*"Es liegt ein vollständiges Detailschema des Prototypen mit Pingranularität vor, d.h. jeder einzelne Pin ist ersichtlich"*
>*"Saubere und übersichtliche Darstellung: keine oder wenig Kreuzungen, nur horizontale oder vertikale Linien, Beschriftung sämtlicher Elemente"*

---

Hier finden sie den Link zur TinkerCAD Seite wo das Blockschaltbild erstellt wurde. Dieses unten noch als Bild aufgezeigt.

[TinkerCAD](https://www.tinkercad.com/things/7osfcFXCBFJ)

![TinkerCAD](https://github.com/ask-yo-girl-about-me/IG1_LEDProjekt/blob/main/03_Projekt/02_TinkerCAD/IG1_LEDProjekt.png)

## Werte-Zuweisungs-Tabelle

---
**Lernziel 2_Design 2**

>*"Die Verknüpfungen (Logik) der Ein- und Ausgangssignale sind vollständig beschrieben"*

---

|  Werte  |  -  |  -  |  -  |
|--------|--------|--------|--------|
|  1  |    |    |    |
|  2  |    |    |    |
|  3  |    |    |    |
|  4  |    |    |    |
|  5  |    |    |    |
|  6  |    |    |    |
|    |    |    |    |
|    |    |    |    |

## Program-Ablauf

---
**Lernziel 2_Design 3**

>*"Der Programmablauf ist mit einer geeigneten Darstellungsmethode (Struktogramm, Flussdiagramm, Statemachine, …) vollständig beschrieben*

>*"Der Programmablauf ist sauber gezeichnet""*

---

Die Datenablage für den Programm-Ablaufen finden Sie hier: [Ablage Programm-Ablauf](https://github.com/ask-yo-girl-about-me/IG1_LEDProjekt/tree/main/03_Projekt/01_Structorizer)

![Struktogramm](https://github.com/ask-yo-girl-about-me/IG1_LEDProjekt/blob/main/03_Projekt/01_Structorizer/IG1_Structorizer.png)

## Definierte-Testcases

---
**Lernziel 2_Design 4**

>*"Es liegt eine Liste mit sämtlichen Testcases, basierend auf den funktionalen und nicht-funktionalen Anforderungen, vor"*

---

Testgruppen

|  Nr.  |  Thema  |  Was?  |  Ergebnis  |
|--------|--------|--------|--------|
|  TG-10  |  Dezibel Meter  |  Der Dezibel Meter wird auf seine funktionalitäten gemäss Funktionalen und nicht-funktionalen Anforderungen überprüft  |    |
|  TG-20  |  Temperatur Meter  |  Der Temperatur Meter wird auf seine funktionalitäten gemäss Funktionalen und nicht-funktionalen Anforderungen überprüft  |    |
|  TG-30  |  Case Change  |  Der Case Change wird auf seine funktionalitäten gemäss Funktionalen und nicht-funktionalen Anforderungen überprüft  |    |
|  TG-40  |  SD Loggin  |  Das loggen auf die SD Karte wird auf seine funktionalitäten gemäss Funktionalen und nicht-funktionalen Anforderungen überprüft  |    |

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

---

# Road to Goal

Schritt für Schritt Text wie wir vorgingen und ans Ziel kamen.

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