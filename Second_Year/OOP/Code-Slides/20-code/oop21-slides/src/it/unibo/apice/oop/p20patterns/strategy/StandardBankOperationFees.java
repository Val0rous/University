package it.unibo.apice.oop.p20patterns.strategy;

public class StandardBankOperationFees implements BankOperationFees {
	
	public int fee(int operationAmount){
		return operationAmount < 1000 ? 1 : 2;
	}
}
