import java.util.Arrays;
import java.util.List;

public class CT7Disc {

    public static void main(String[] args) {
        // 1. Set up some dummy log data to process
        List<String> serverLogs = Arrays.asList(
            "INFO: Server started successfully on port 8080.",
            "WARN: High memory usage detected.",
            "ERROR_500: Database connection timeout.",
            "INFO: User 'admin' login successful.",
            "ERROR_500: NullPointerException in payment module."
        );

        System.out.println("Starting log processor...");
        System.out.println("-------------------------");
        
        // 2. Call the method that uses minimized scope
        processLogs(serverLogs);
        
        System.out.println("-------------------------");
        System.out.println("Processing complete.");
    }

    /**
     * Processes a list of logs, demonstrating minimized variable scope.
     */
    public static void processLogs(List<String> logs) {
        // 'currentLog' is scoped strictly to this for-each loop.
        for (String currentLog : logs) { 
            
            // 'hasError' is scoped strictly to this current iteration.
            // It is created, evaluated, and destroyed on every loop pass.
            boolean hasError = currentLog.contains("ERROR_500"); 

            if (hasError) {
                System.out.println("Found error in: " + currentLog);
            }
        }
    }
}