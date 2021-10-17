libSimuClient 0.5	05.04.2010

SimuClient fuer MacOS 10.6/Linux (Praktikum Informatik 2, WS 2009/10 RWTH Aachen)
(c) Robert Uhl 2009 - 2010
Inhalt: SimuClient sendet Daten an den (erweiterten) Java-Grafik-Server

Beschreibung:
Fuegt die zwei .cpp und .h Dateien aus dem Ordner Quellcode einfach Eurem Projekt hinzu.
Die Verkehrssimulation sollte fuer i386/Release
kompiliert werden, nicht x64 (kann zu Problemen z.B. mit stringstream fuehren).

ANPASSUNGEN:
Die Bibliothek kann im Quellcode genau so wie die vorgegebene des Praktikums
verwendet werden, es sollten keine groesseren Anpassungen noetig sein!
Lediglich der Praeprozessorbefehl #pragma once sollte durch eine #ifndef-Abfrage
ersetzt werden. Und #include <windows.h> natuerlich auskommentieren ;-)
Weiter ist aufgefallen, dass in LazyAktion.h bei den Klassen LazyPushFront,
LazyPushBack und LazyErase in der Funktion vAusfuehren() ein "LazyAktion<T>::"
vor p_ptLazyListe ergaenzt werden muss, da der gcc sonst nicht kompiliert.
(Also z.B. LazyAktion<T>::p_ptLazyListe->push_front(p_tObjekt); in LazyPushFront)
Ebenfalls muss in LazyListe.h in der Funktion vAktualisieren() der Iterator als
typename list<LazyAktion<T>*>::const_iterator itL; angegeben werden (also typename ergaenzen!).


Der libSimuClient wurde erfolgreich unter OpenSUSE 11.2 und MacOS X getestet.
Natuerlich uebernehme ich keine Garantie fuer die Funktionsfaehigkeit oder Programmfehler ;-)
Ueber weitere Rueckmeldungen wuerde ich mich freuen.


WICHTIG:
Um die Funktionalitaet der Fehlermeldungen und die Anzeige der Simulationszeit in der Titelzeile
auch mit diesem SimuClient nutzen zu koennen, muss der erweiterte SimuServer verwendet werden,
den es auf meiner Webseite auch als Download gibt!


Start der Simulation:
SimuServer.jar in das selbe Verzeichnis kopieren, in dem sich auch die ausfuehrbare
Verkehrssimulation befindet!
Der SimuClient startet nun standardmaessig von selbst den GrafikServer.
Ist dies nicht gewuenscht, der Funktion bInitialisiereGrafik() den Parameter
bStarteServer als false uebergeben.
Es kann passieren, dass der Start beim ersten Mal nicht sofort funktioniert.
Dann bitte den Server beenden und die Verkehrssimulation nochmal starten, dann sollte
es funktionieren.


Wer Fehler/Unklarheiten in der Bibliothek findet, schreibt mir bitte eine
eMail an robert.uhl@rwth-aachen.de
Vielen Dank an Herrn Schnitzler vom EECS fuer den Zugang zu allen Quellcodes.

Viel Spass im Praktikum!


TODO:

NEW/FIXES:
- DEBUG im ClientSocket deaktiviert
- LazyListe Aenderungen fuer gcc in der ReadMe eintragen
- Sleep() Funktion hinzugefuegt, die wie unter Windows Millisekunden uebernimmt
- vSetzeZeit() sendet die uebergebene Zeit an den erweiterten SimuServer
- Fehlermeldungen des SimuClient werden an den erweiterten SimuServer geschickt
	und dort als MessageBox angezeigt
