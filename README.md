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

Für die Anzeige des Klassendiagramms verwenden Sie bitte VS Code mit der Extension `UMLet`. Sollten Sie das Klassendiagramm nicht öffnen können, finden Sie einen Screenshot im `readme-resources`-Ordner

[^1]: Genannte Komponenten können auch nach der Installation von VS noch installiert werden, dazu den Visual Studio Installer erneut aufrufen und bei der entsprechenden Installation auf `Ändern` klicken

[^2]: Klonen in Visual Studio ist über `Datei` -> `Repository klonen` möglich

## Funktion Smart-Bot
Der Smart-Bot in unserem Projekt durchläuft fünf Algorithmen, um seinen nächsten Zug zu wählen. In jeder Stufe versucht der Bot, einen geeigneten und möglichst effektiven Zug zu finden. Findet er in einer Stufe einen Zug, führt er diesen aus und der Zug ist beendet, falls nicht, geht er in die nächste Stufe.
Die Stufen, unterschieden in harte und softe Kriterien, funktionieren wie folgt:
1. [hart] Versuche zu gewinnen; betrachte für die Suche die Position, an die der Bot selbst zuletzt gesetzt hat
    * Prüfe, ob zwei eigene Symbole nebeneinander liegen und ein drittes daneben platziert werden kann
    * Prüfe, ob zwischen zwei eigenen Symbolen eine Lücke ist, in die platziert werden kann
2. [hart] Blockiere die Chance eines beliebigen Gegners; durchsuche dafür das gesamte Feld
    * Prüfe, ob zwei fremde Symbole nebeneinander liegen und ein drittes zum Blockieren daneben platziert werden kann
    * Prüfe, ob zwischen zwei fremden Symbolen eine Lücke ist, in die zum Blockieren gesetzt werden kann
3. [soft] Versuche, neben den zuletzt selbst gesetzten Chip zu legen, um ein Paar zu bilden
    * Prüfe alle Felder um das letzte Feld und setze in das Erste, das frei ist
4. Sollte das Feld in der Mitte noch frei sein, platziere dort
5. Setze in ein zufälliges, freies Feld

## Mögliche Erweiterung um mehr Spielertypen
Alle Spieler erben aus der Klasse `Player` und überschreiben die Funktion `makeMove`, die festlegt, wie der jeweilige Spieler zieht.
Um also z.B. einen weiteren Bot einzufügen, wäre das Vorgehen folgendermaßen:
* Erstelle eine neue Klasse und lasse diese aus `Player` erben
* Spezifiere das Zugverhalten des Spielers durch Überschreiben der `makeMove`
* Füge im `GameManager` eine neue Abfrage zu Beginn des Spiels für die Menge an Spielern von diesem Typ hinzu


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

### Ausführung im Debug-Modus
Bei der Ausführung im Debug-Modus kommt es, bei bestimmten Konstellationen von Feldgröße und Spielerzahl, innerhalb von Google Test zu dem Fehler `bad-allocation`.
Wir sind uns diesem Fehler bewusst, haben jedoch auch nach langer Suche im Internet keine Ursache für das Problem gefunden. Beim Ausführen ohne Debuggen tritt dieser Fehler nie auf.
