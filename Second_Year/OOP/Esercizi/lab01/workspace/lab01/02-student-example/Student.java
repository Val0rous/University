class Student {

    // ... Aggiungere qui la definizione dei campi
    String name;
    String surname;
    int id;
    int matriculationYear;

    void build(String name, String surname, int id, int matriculationYear) { /* Aggiungere i parametri di input */
        // ... Inizializzazione dei campi della classe
        this.name = name;
        this.surname = surname;
        this.id = id;
        this.matriculationYear = matriculationYear;
    }

    void printStudentInfo() {
        /*
         * Aggiungere i comandi per la stampa delle informazioni sullo studente
         */
        System.out.println(this.name + " " + this.surname + ": #" + this.id 
                + ", matriculated in " + this.matriculationYear);
    }
}
