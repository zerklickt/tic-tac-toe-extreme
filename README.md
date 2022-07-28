# tic-tac-toe-extreme
Tic-Tac-Toe Extreme

Abschlussprojekt C++ ITA21

Programmiert von Simon Rohrbach und Nick Hoschke
## Installation und Ausführen
1. Installation von Visual Studio
2. Stellen Sie bitte sicher, dass folgende Komponenten unter `Desktopentwicklung mit C++` mitinstalliert werden[^1]:
- `C++-CMake-Tools für Windows`
- `Testadapter für Boost.Test`
- `Testadapter für Google Test`
3. Klonen des Repos (wir empfehlen das Klonen über die eingebaute Funktion in Visual Studio[^2], da sämtliche Abhängigkeiten und gerätespezifische Einstellungen automatisch eingerichtet werden.)
4. Starten des Programms über `Debuggen` -> `Starten ohne debuggen`

[^1]: Genannte Komponenten können auch nach der Installation von VS noch installiert werden, dazu den Visual Studio Installer erneut aufrufen und bei der entsprechenden Installation auf `Ändern` klicken

[^2]: Klonen in Visual Studio ist über `Datei` -> `Repository klonen` möglich

## Hinweise
### Programmstruktur
- Beim Starten des Programms wird zuerst das normale Programm und abschließend die implementierten Unit-Tests ausgeführt. Wenn Sie auf die Unit-Tests verzichten wollen, erstzen Sie das return-statement in der `main.cpp` durch ein `return 0;`

### Dateistruktur
Die Dateistruktur im Repository sieht sehr unstrukturiert aus, da alle Dateien im selben Ordner liegen. Wenn der Import in Visual Studio korrekt funktioniert hat, sind die Dateien in Filtern abgelegt, um somit eine package-ähnliche Struktur bei der Entwicklung zu ermöglichen.

### Struktur der config-Datei
Nach der Syntax der Config-Datei sind Parameter immer in der nächsten Zeile nach ihrem jeweiligen Key einzutragen
Beispiel:
```
Fieldheight:
15

[key]:
<value>
```
