Einbinden der Dateien in das Projekt:

1.
  - SimuClient.h ins Arbeitsverzeichnis (src) kopieren.
  - SimuServer.jar ins Projektverzeichnis kopieren.
  - libsimu.so ins Verzeichnis /usr/lib kopieren
  - eventuell Refresh der IDE nötig. Unter Eclipse z.B. Rechtsklick auf das Projekt -> Refresh

2. Linker-Einstellungen des Projekts so ändern, dass er die libsimu.so einbindet.
    
  In Eclipse:
    Project Properties -> C/C++ Build -> Settings -> Tool Settings -> GCC C++ Linker -> Libraries
    Bei Libraries "simu" (ohne Anführungszeichen) hinzufügen.

  Für andere IDE oder manuelles Kompilieren:
    Dem Linker muss die Option -lsimu übergeben werden.
    (entspricht "-l"-Option mit dem Library-Namen ohne beginnendes "lib" und ".so"-Endung)
    D.h. der Aufruf sollte so aussehen:
    g++ -o"Ausgabedatei" [src-Dateien] -lsimu

Thomas Dondorf