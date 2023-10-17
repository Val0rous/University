class TestComplexNum {

  /*
  //a = a + b
  static void sumToNum(ComplexNum a, ComplexNum b) {
    a.re = a.re + b.re;
    a.im = a.im + b.im;
  }
  */
  public static void main(String[] args) {
      /*
       * Testare la classe come segue:
       *
       * 1) Creare il numero complesso 3+5i e memorizzarlo nella variabile c1
       *
       * 2) Creare il numero complesso 7-4i e memorizzarlo nella variabile c2
       *
       * 3) Creare il numero complesso -2+3i e memorizzarlo nella variabile c3
       *
       * 4) Creare il numero complesso -2+3i e memorizzarlo nella variabile c4
       *
       * 5) Stampare in standard output la rappresentazione testuale di
       * c1,c2,c3,c4 restituita dal metodo toStringRep()
       *
       * 6) Sommare a c1 c2
       * (somma di due num complessi (a + ib) + (c + id) = (a + c) + i(b + d)
       *
       * 7) Sommare a c2 c4
       *
       * 8) Stampare nuovamente in standard output la rappresentazione testuale
       * di c1,c2,c3,c4
       *
       * 9) Controllare se l'output corrisponde a quanto preventivato
       *
       * 10) Invocare il metodo equal su c3 per tre volte, passando come input
       * c1,c2,c4. Stampare il risultato di ciascuna invocazione in standard
       * output
       *
       * 11) Controllare se l'output corrisponde a quanto preventivato
       */

      ComplexNum c1 = new ComplexNum();
      c1.re = 3;
      c1.im = 5;

      ComplexNum c2 = new ComplexNum();
      c2.re = 7;
      c2.im = -4;

      ComplexNum c3 = new ComplexNum();
      c3.re = -2;
      c3.im = 3;

      ComplexNum c4 = new ComplexNum();
      c4.re = -2;
      c4.im = 3;

      System.out.println(c1.toStringRep());
      System.out.println(c2.toStringRep());
      System.out.println(c3.toStringRep());
      System.out.println(c4.toStringRep());
       
      //c1 =+ c2
      c1.re = c1.re + c2.re;
      c1.im = c1.im + c2.im;
      ////c1 = sumToNum(c1, c2);

      //c2 += c4
      c2.re = c2.re + c4.re;
      c2.im = c2.im + c4.im;
      ////c2 = sumToNum(c2, c4);

      System.out.println(c1.toStringRep());
      System.out.println(c2.toStringRep());
      System.out.println(c3.toStringRep());
      System.out.println(c4.toStringRep());

      System.out.println("c3 == c1 " + c3.equal(c1));
      System.out.println("c3 == c2 " + c3.equal(c2));
      System.out.println("c3 == c4 " + c3.equal(c4));
  }
}
