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
- [Testing](#testing)
  - [Durchführung-Testcases](#durchführung-testcases)
- [Reflexion (Problemstellungen)](#reflexion-problemstellungen)
- [Fazit](#fazit)

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

# Analyse
Hier bei der Analyse werden alle nötigen Infos definiert aufgezeigt, welche man für die Realisation braucht.

## Funktionale Anforderungen


## Nicht-funktionale Anforderungen


## Signalbeschrieb


## Blockschaltbild
Hier finden sie den Link zur TinkerCAD Seite wo das Blockschaltbild erstellt wurde. Dieses unten noch als Bild aufgezeigt.

[TinkerCAD](https://www.tinkercad.com/things/7osfcFXCBFJ)

![TinkerCAD](https://github.com/ask-yo-girl-about-me/IG1_LEDProjekt/blob/main/03_Projekt/02_TinkerCAD/IG1_LEDProjekt.png)

# Design


## Detailschema


## Werte-Zuweisungs-Tabelle


## Program-Ablauf
Die Datenablage für den Programm-Ablaufen finden Sie hier: [Ablage Programm-Ablauf](https://github.com/ask-yo-girl-about-me/IG1_LEDProjekt/tree/main/03_Projekt/01_Structorizer)

![Struktogramm](https://github.com/ask-yo-girl-about-me/IG1_LEDProjekt/blob/main/03_Projekt/01_Structorizer/IG1_Structorizer.png)

## Definierte-Testcases
|  Test-Case  |  Thema  |  Was?  |  Ergebnis  |
|--------|--------|--------|--------|
|  1  |    |    |    |
|  2  |    |    |    |
|  3  |    |    |    |
|  4  |    |    |    |
|  5  |    |    |    |
|  6  |    |    |    |
|    |    |    |    |
|    |    |    |    |


# Implementierung


## Realisierung


## Source-Code


# Testing


## Durchführung-Testcases


# Reflexion (Problemstellungen)
- LED Streifen
- Programmsprache C
- FastLED Library welche nur ging wenn man MKR1000 ausgewählt hat

# Fazit


>«Wir erklären hiermit, dass wir diese Arbeit selbständig verfasst und keine anderen als die angegebenen Quellen benutzt haben. Alle Stellen, die wörtlich oder sinngemäss aus Quellen entnommen wurden, haben wir als solche gekennzeichnet.»

[^1]:
[^2]:
[^3]:
[^4]:
[^5]:
[^6]:
[^7]: