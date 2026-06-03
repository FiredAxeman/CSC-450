public class main {

    public static void main(String[] args) {
        
        // Thread 1: Counts up from 0 to 20
        Thread thread1 = new Thread(() -> {
            System.out.println("Thread 1 starting...");
            for (int i = 0; i <= 20; i++) {
                System.out.println("Thread 1: " + i);
                try {
                    // Slight delay to simulate processing time
                    Thread.sleep(100); 
                } catch (InterruptedException e) {
                    Thread.currentThread().interrupt();
                    System.err.println("Thread 1 was interrupted.");
                }
            }
            System.out.println("Thread 1 finished.");
        });

        // Thread 2: Counts down from 20 to 0
        Thread thread2 = new Thread(() -> {
            System.out.println("Thread 2 starting...");
            for (int i = 20; i >= 0; i--) {
                System.out.println("Thread 2: " + i);
                try {
                    Thread.sleep(100);
                } catch (InterruptedException e) {
                    Thread.currentThread().interrupt();
                    System.err.println("Thread 2 was interrupted.");
                }
            }
            System.out.println("Thread 2 finished.");
        });

        // Execution control
        try {
            thread1.start();
            thread1.join(); // Main thread waits for thread1 to finish
            
            thread2.start();
            thread2.join(); // Main thread waits for thread2 to finish
            
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
            System.err.println("Main execution was interrupted.");
        }
        
        System.out.println("Application completed successfully.");
    }
}