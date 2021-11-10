public class BankAccount {
    public class Builder {
        private long accountNumber;
        private String owner;
        private String branch;
        private double balance;
        private double interestRate;

        public Builder(long accountNumber) {
            this.accountNumber = accountNumber;
        }

        public Builder withOwner(String owner){
            this.owner = owner;

            return this;
        }

        public Builder atBranch(String branch){
            this.branch = branch;

            return this;
        }

        public Builder openingBalance(double balance){
            this.balance = balance;

            return this;
        }

        public Builder atRate(double interestRate){
            this.interestRate = interestRate;

            return this;
        }

        public BankAccount build(){
            BankAccount account = new BankAccount();
            account.accountNumber = this.accountNumber;
            account.owner = this.owner;
            account.branch = this.branch;
            account.balance = this.balance;
            account.interestRate = this.interestRate;

            return account;
        }
    }

    private long accountNumber;
    private String owner;
    private String branch;
    private double balance;
    private double interestRate;

    private BankAccount() {}
}

class Program {
    public static void Main(string[] args) {
        BankAccount account = new BankAccount.Builder(1234567890L)
            .withOwner("John Doe")
            .atBranch("ABC Bank")
            .openingBalance(100.0)
            .atRate(0.1)
            .build();
    }
}

Program.Main(null);