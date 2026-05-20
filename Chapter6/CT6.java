import java.io.Serializable;
import java.util.logging.Logger;

// NONCOMPLIANT: Implements Serializable without protecting sensitive fields
public class UserProfile implements Serializable {
    private static final long serialVersionUID = 1L;
    private static final Logger logger = Logger.getLogger(UserProfile.class.getName());

    private String username;

    // NONCOMPLIANT: Storing passwords and credit cards as immutable Strings
    private String password;
    private String creditCardNumber;

    public UserProfile(String username, String password, String creditCardNumber) {
        this.username = username;
        this.password = password;
        this.creditCardNumber = creditCardNumber;

        // NONCOMPLIANT: Logging sensitive data upon creation
        logger.info("New UserProfile created: " + this.toString());
    }

    public void processPayment(double amount) {
        // Simulating a failure that leaks state
        if (amount <= 0) {
            // NONCOMPLIANT: Leaking sensitive variables into Exception messages
            throw new IllegalArgumentException(
                "Invalid amount " + amount + " for card " + creditCardNumber
            );
        }
        System.out.println("Processing $" + amount + " for user " + username);
    }

    // NONCOMPLIANT: Default toString() implementation exposes all fields
    @Override
    public String toString() {
        return "UserProfile{" +
                "username='" + username + '\'' +
                ", password='" + password + '\'' +
                ", creditCardNumber='" + creditCardNumber + '\'' +
                '}';
    }
}