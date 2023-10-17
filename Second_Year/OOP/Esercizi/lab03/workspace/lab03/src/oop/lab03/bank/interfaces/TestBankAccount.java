package oop.lab03.bank.interfaces;

import oop.lab03.bank.StrictBankAccount;
import oop.lab03.bank.AccountHolder;
import oop.lab03.bank.SimpleBankAccount;

public final class TestBankAccount {

    private TestBankAccount() {
    }

    public static void main(final String[] args) {
        /*
         * 1) Creare l' AccountHolder relativo a Mario Rossi con id 1
         */
    	AccountHolder mario = new AccountHolder("Mario", "Rossi", 1);
        /*
         * 2) Creare l' AccountHolder relativo a Luigi Bianchi con id 2
         */
    	AccountHolder luigi = new AccountHolder("Luigi", "Bianchi", 2);
        /*
         * 3) Dichiarare due variabili di tipo BankAccount ed inizializzarle,
         * rispettivamente, con oggetti di tipo SimpleBankAccount per il conto di Mario
         * Rossi (ammontare iniziale = 0), e di tipo StrictBankAccount per il conto di
         * Luigi Bianchi (ammontare iniziale = 0)
         */
    	BankAccount marioBank = new SimpleBankAccount(mario.getUserID(), 0);
    	BankAccount luigiBank = new StrictBankAccount(luigi.getUserID(), 0);
        /*
         * 4) Prima riflessione: perché è stato possibile fare la new di due classi
         * diverse in variabili dello stesso tipo?
         */
    	//Perché estendono la stessa interfaccia, di conseguenza supportano le stesse operazioni
        /*
         * 5) Depositare €10000 in entrambi i conti
         */
    	marioBank.deposit(mario.getUserID(), 10000);
    	luigiBank.deposit(luigi.getUserID(), 10000);
        /*
         * 6) Prelevare €15000 da entrambi i conti
         */
    	marioBank.withdraw(mario.getUserID(), 15000);
    	luigiBank.withdraw(luigi.getUserID(), 15000);
        /*
         * 7) Stampare in stdout l'ammontare corrente
         */
    	System.out.println(mario.toString() + " : $" + marioBank.getBalance());
    	System.out.println(luigi.toString() + " : $" + luigiBank.getBalance());
        /*
         * 8) Qual è il risultato e perché?
         */
    	//sottozero per Mario, invariato per Luigi, due to implementation differences
        /*
         * 9) Depositare nuovamente €10000 in entrambi i conti
         */
    	marioBank.deposit(mario.getUserID(), 10000);
    	luigiBank.deposit(luigi.getUserID(), 10000);
        /*
         * 10) Invocare il metodo computeManagementFees su entrambi i conti
         */
    	marioBank.chargeManagementFees(mario.getUserID());
    	luigiBank.chargeManagementFees(luigi.getUserID());
        /*
         * 11) Stampare a video l'ammontare corrente
         */
    	System.out.println(mario.toString() + " : $" + marioBank.getBalance());
    	System.out.println(luigi.toString() + " : $" + luigiBank.getBalance());
        /*
         * 12) Qual è il risultato e perché?
         */
    	//no fee for Mario, small fee for Luigi, due to implementation differences

    }
}
