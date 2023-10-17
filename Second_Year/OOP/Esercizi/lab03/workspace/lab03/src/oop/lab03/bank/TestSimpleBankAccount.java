package oop.lab03.bank;

public final class TestSimpleBankAccount {

    private TestSimpleBankAccount() { }

    public static void main(final String[] args) {
        /*
         * 1) Creare l' AccountHolder relativo a Mario Rossi con id 1 
         * 2) Creare l' AccountHolder relativo a Luigi Bianchi con id 2 
         * 3) Creare i due SimpleBankAccount corrispondenti 
         * 4) Effettuare una serie di depositi e prelievi 
         * 5) Stampare a video l'ammontare dei due conti e verificare
         * la correttezza del risultato 
         * 6) Provare a prelevare fornendo un idUsr sbagliato 
         * 7) Controllare nuovamente l'ammontare
         */
    	
    	AccountHolder mario = new AccountHolder("Mario", "Rossi", 1);
    	AccountHolder luigi = new AccountHolder("Luigi", "Bianchi", 2);
    	
    	SimpleBankAccount marioBank = new SimpleBankAccount(mario.getUserID(), 0);
    	SimpleBankAccount luigiBank = new SimpleBankAccount(luigi.getUserID(), 0);
    	
    	marioBank.deposit(mario.getUserID(), 100);
    	luigiBank.deposit(luigi.getUserID(), 1000);
    	luigiBank.withdraw(luigi.getUserID(), 200);
    	marioBank.depositFromATM(mario.getUserID(), 700);
    	marioBank.withdrawFromATM(mario.getUserID(), 50);
    	
    	marioBank.printBalance(mario, mario.getUserID());
    	luigiBank.printBalance(luigi, luigi.getUserID());
    	
    	luigiBank.withdraw(mario.getUserID(), 40);
    	
    	luigiBank.printBalance(luigi, luigi.getUserID());
    }
}
