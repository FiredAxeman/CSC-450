import java.util.logging.Level;
import java.util.logging.Logger;

class InsufficientFundsException extends RuntimeException {
    private final double deficit;

    public InsufficientFundsException(String message, double deficit) {
        super(message);
        this.deficit = deficit;
    }

    public double getDeficit() {
        return deficit;
    }
    @Override
    public synchronized Throwable fillInStackTrace() {
        return this;
    }
}
class BankAccount {
    private double balance;

    public BankAccount(double balance) {
        this.balance = balance;
    }

    public void withdraw(double amount) {
        // Validation: Throw early
        if (amount <= 0) {
            throw new IllegalArgumentException("Withdrawal amount must be positive.");
        }

        // Business Rule: Throw custom exception
        if (amount > balance) {
            double deficit = amount - balance;
            throw new InsufficientFundsException("Cannot process withdrawal.", deficit);
        }

        balance -= amount;
        System.out.println("Remaining balance: $" + balance);
    }
}
class TransactionService {
    private static final Logger logger = Logger.getLogger(TransactionService.class.getName());
    public void processUserWithdrawal(BankAccount account, double amount) {
        try {
            System.out.println("\n--- Attempting to withdraw $" + amount + " ---");
            account.withdraw(amount);
            System.out.println("Withdrawal successful. Please take your cash.");
        } catch (InsufficientFundsException e) {
            System.out.println("Transaction declined: Your account is short by $" + e.getDeficit());

        } catch (IllegalArgumentException e) {
            System.out.println("Transaction declined: " + e.getMessage());

        } catch (Exception e) {
            logger.log(Level.SEVERE, "Unexpected system error during withdrawal", e);
            System.out.println("We are experiencing technical difficulties. Please try again later.");
        }
    }
}

// 4. Main Executable Class
public class CT8disc {
    public static void main(String[] args) {
        BankAccount myAccount = new BankAccount(100.00);
        TransactionService service = new TransactionService();
        service.processUserWithdrawal(myAccount, 40.00);
        service.processUserWithdrawal(myAccount, 80.00);
        service.processUserWithdrawal(myAccount, -20.00);
        System.out.println("\n--- Attempting to process a broken transaction ---");
        service.processUserWithdrawal(null, 50.00);
    }
}