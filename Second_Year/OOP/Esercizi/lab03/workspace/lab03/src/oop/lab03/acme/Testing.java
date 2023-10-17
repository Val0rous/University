package oop.lab03.acme;

public final class Testing {

    private Testing() { }

    public static void main(final String[] args) {
        /*
         * 1) Creare 3 studenti a piacere 
         * 2) Creare 2 docenti a piacere 
         * 3) Creare due aulee di esame, una con 100 posti 
         * una con 80 posti 
         * 4) Creare due esami, uno con nMaxStudents=10, 
         * l'altro con nMaxStudents=2
         * 5) Iscrivere tutti e 3 gli studenti agli esami 
         * 6) Stampare in stdout la rapresentazione in stringa 
         * dei due esami
         */
    	
    	Student eugi = new Student(1, "Eugenio", "Rossi", "ross.euge", 2020);
    	Student paga = new Student(2, "Giacomo", "Paganelli", "paga.giac", 2020);
    	Student vale = new Student(3, "Francesco", "Valentini", "vale.fran", 2020);
    	
    	Professor adam = new Professor(1, "Adam Paolo", "Razzino", "razz.adam", new String[] {"OOP", "ANAL", "OS"});
    	Professor paolo = new Professor(2, "Paolo", "Mancuso", "manc.paol", new String[] {"Storia", "Scienze Motorie", "ASD"});
    	
    	ExamRoom bigRoom = new ExamRoom(100, "Aula (MAGNA) 3.4", true, true);
    	ExamRoom smallRoom = new ExamRoom(80, "Aula 2.12", true, true);
    	
    	Exam oop = new Exam(1, 10, "OOP", adam, bigRoom);
    	Exam asd = new Exam(2, 2, "ASD", paolo, smallRoom);
    	
    	oop.registerStudent(vale);
    	oop.registerStudent(paga);
    	oop.registerStudent(eugi);
    	
    	asd.registerStudent(vale);
    	asd.registerStudent(paga);
    	asd.registerStudent(eugi);
    	
    	System.out.println(oop.toString());
    	System.out.println(asd.toString());
    }
}
