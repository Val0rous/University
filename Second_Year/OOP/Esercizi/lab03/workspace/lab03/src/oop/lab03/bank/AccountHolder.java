package oop.lab03.bank;

public class AccountHolder {

    private final String name;
    private final String surname;
    private final Integer userID;

    public AccountHolder(final String name, final String surname, final Integer accountID) {
        this.name = name;
        this.surname = surname;
        this.userID = accountID;
    }

    public String getName() {
        return this.name;
    }

    public String getSurname() {
        return this.surname;
    }

    public Integer getUserID() {
        return this.userID;
    }

    public String toString() {
    	
    	return (this.name + " " + this.surname + ": ID #" + this.userID);
    }
}
