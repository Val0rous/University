class TestStudent {
  public static void main(String[] args) {
      Student student = new Student();
      /*
       * aggiornare l'invocazione del metodo build con l'aggiunta dei
       * parametri
       */
      student.build("Francesco", "Valentini", 970197, 2020);
      student.printStudentInfo();
      /*
       * Creare dei nuovi oggetti relativi agli studenti:
       *
       * - Nome: Luigi Cognome: Gentile id: 1015, matriculationYear: 2019
       * - Nome: Simone Cognome: Bianchi id: 1016, matriculationYear: 2018
       * - Nome: Andrea Cognome: Bracci id: 1017, matriculationYear: 2017
       *
       * Stampare a video le informazioni relative a ciascuno studente.
       */
      Student luigi = new Student();
      luigi.build("Luigi", "Gentile", 1015, 2019);
      luigi.printStudentInfo();

      Student simone = new Student();
      simone.build("Simone", "Bianchi", 1016, 2018);
      simone.printStudentInfo();

      Student andrea = new Student();
      andrea.build("Andrea", "Bracci", 1017, 2017);
      andrea.printStudentInfo();
  }
}
