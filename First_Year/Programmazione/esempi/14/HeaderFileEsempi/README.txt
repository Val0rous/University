Nota: mostrare tre modi di fare librerie:
1) Creare un progetto con file main.c e MyLibrary.c. Creare un nuovo "progetto header" con i descrittori delle funzioni nel file "MyLibrary.c". Chiamare il file "MyLibrary.h".
2) Creare un progetto "Static Library" e fare e compilare la libreria "###MyLibrary.a". Creare poi un progetto con file main.c e "MyLibrary.h" con i descrittori delle funzioni nel file "###MyLibrary.a" e con il menu del linker lincare il progetto della librezia. Vedere il seguente vdeo per avere un esempio: https://www.youtube.com/watch?v=-3BoOuSSCeI
3) Creare un file .h con direttamente le funzioni e metterlo a mano nelle cartelle di Code::Blocks (tipicamente MinGW/Include). Vedere il seguente video per avere un esempio: https://www.youtube.com/watch?v=yU_qh9i3auU

Nota: differenza tra <...> e "..." in include:
La differenza è nella posizione in cui il preprocessore cerca il file incluso.
In #include "filename" il preprocessore cerca nella stessa directory del file che contiene la chiamata #include e poi procede come per #include <filename>. Questo metodo viene normalmente utilizzato per includere file di intestazione definiti dal programmatore.
In #include <filename> il preprocessore ricerca in modo dipendente dall'implementazione, normalmente nelle directory di ricerca pre-definite dal compilatore/IDE. Questo metodo viene normalmente utilizzato per includere file di intestazione di libreria standard.
