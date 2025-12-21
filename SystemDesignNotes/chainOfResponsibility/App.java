import logger.* ; 
import logProcessor.* ;

public class App {
    public static void main(String args[]){
        LogProcessor log  = Logger.getLogger() ; 
        System.out.println("\n\nlogging the debug message") ;
        log.logMessage(LogProcessor.DEBUG, "Log this payment");

        System.out.println("\n\nlogging the debug message") ;
        log.logMessage(LogProcessor.INFO, "Log this Order");

        System.out.println("\n\nlogging the debug message") ;
        log.logMessage(LogProcessor.FATAL, "Log this server failure of application shoping cart");

        System.out.println("\n\nlogging the debug message") ;
        log.logMessage(LogProcessor.ERROR, "Log this failed to process Checkout");
        return ; 
    }
}