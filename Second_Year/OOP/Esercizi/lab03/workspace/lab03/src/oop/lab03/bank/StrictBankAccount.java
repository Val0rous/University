package oop.lab03.bank;

import oop.lab03.bank.interfaces.BankAccount;

public class StrictBankAccount implements BankAccount {

	private double balance;
	private int userID;
	private int nTransactions;
	private static double ATM_TRANSACTION_FEE = 1;
	
	public StrictBankAccount(final int userID, final double balance) {
		this.userID = userID;
		this.balance = balance;
		this.nTransactions = 0;
	}
	
	public int getUserID() {
		return this.userID;
	}
		
	@Override
	public void withdraw(int usrID, double amount) {
		if((this.checkUser(usrID) == true) && ((this.balance - amount) >= 0)) {
    		this.nTransactions++;
    		this.balance -= amount;
    	}		
	}

	@Override
	public void deposit(int usrID, double amount) {
		if(this.checkUser(usrID) == true) {
    		this.nTransactions++;
    		this.balance += amount;
    	}
	}

	@Override
	public void depositFromATM(int usrID, double amount) {
		if((this.checkUser(usrID) == true) && (amount > ATM_TRANSACTION_FEE)) {
    		this.nTransactions++;
    		this.balance = (this.balance + amount - ATM_TRANSACTION_FEE);
    	}
	}

	@Override
	public void withdrawFromATM(int usrID, double amount) {
		if((this.checkUser(usrID) == true)  && ((this.balance - amount) >= 0)) {
    		this.nTransactions++;
    		this.balance = (this.balance - amount - ATM_TRANSACTION_FEE);
    	}
	}

	@Override
	public void chargeManagementFees(int usrID) {
		this.balance = this.balance - (5 + 0.1 * this.nTransactions);
	}

	@Override
	public double getBalance() {
	return this.balance;
	}

	@Override
	public int getTransactionsCount() {
		return this.nTransactions;
	}
	
	/* Utility method per controllare lo user */
    private boolean checkUser(final int id) {
        return this.userID == id;
    }
    
    public void printBalance(final AccountHolder person, final int usrID) {
    	if(this.checkUser(usrID) == true) {
	    	System.out.println(person.toString() + " : $" + this.balance);
    	}
    }
}
