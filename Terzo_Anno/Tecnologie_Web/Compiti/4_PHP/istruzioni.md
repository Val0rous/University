Scrivere il codice PHP valido (ovvero che esegua correttamente su server web Apache) che legga i dati che gli sono stati inviati tramite GET nelle variabili "A", "B" e "O".  

In questa pagina, occorrerà:  
- Controllare che le variabili "A" e "B" non siano nulle e che siano valide, ovvero che siano numeri positivi e che sul db ci siano numeri appartenenti a quell'insieme  
- Controllare che la variabile "O" non sia nulla e che sia uguale a "i" o "u".  
- Leggere tutti i numeri appartenenti a ciascun insieme (A o B) su database e inserirli in due vettori distinti.  
- Creare un nuovo vettore contenente l'unione dei due insiemi se O vale u, altrimenti dovrà contenere l'intersezione dei due insiemi.  
- Inserire sul db il nuovo insieme, usando come id dell'insieme il successivo all'id massimo.  
- Dovete supporre che il db esista (nome database: giugno; nome tabella: insiemi; username: root, pw: ''), e che il demone mysql sia in ascolto sulla porta 3306 e che la tabella "insiemi" sia strutturata e riempita secondo le istruzioni che trovate nel file "README_DB.txt".  
- Consegnato solamente il file vostraemailunibo.php  

Esempi con i dati di esempio presenti nel file README_DB.txt:  
Se A=1, B=2 e O=u i seguenti numeri dovranno essere inseriti all'interno del db (colonna valore): 19, 2, 14, 98, 1. Tutte queste righe avranno il valore 3 nella colonna insieme.  
Se A=1, B=" e O=i i seguenti numeri dovranno essere inseriti all'interno del db (colonna valore): 19. Questa riga avrà il valore 3 nella colonna insieme.  
