# tic-tac-toe-extreme
[![Made-for-Visual Studio](https://img.shields.io/badge/Made%20for-Visual%20Studio-blue.svg)](https://visualstudio.microsoft.com/de/downloads/)

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
Die Standardansicht in Visual Studio zeigt keine Filter an, falls also im Projektmappen-Explorer keine Filter zu sehen sind und die Wurzel des Projektbaums keine Projektmappe ist, bitte auf dieses Symbol ![icon](https://github.com/zerklickt/tic-tac-toe-extreme/blob/cdbbd8ca0f4b65576ed6afe9b9034ab9edcf632d/readme-resources/switch-view-icon.png?raw=true) und anschließend doppelt auf `TicTacToeExtreme.sln` klicken.

### Struktur der config-Datei
Nach der Syntax der Config-Datei sind Parameter immer in der nächsten Zeile nach ihrem jeweiligen Key einzutragen
Beispiel:
```
Fieldheight:
15

[key]:
<value>
```
