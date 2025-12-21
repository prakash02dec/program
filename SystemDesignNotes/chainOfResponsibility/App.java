import logger.* ; 
import logProcessor.* ;

public class App {
    public static void main(String args[]){
        LogProcessor log  = Logger.getLogger() ; 
        System.out.println("\n\nlogging the Debug message") ;
        log.logMessage(LogType.DEBUG, "Log this payment");

        System.out.println("\n\nlogging the Info message") ;
        log.logMessage(LogType.INFO, "Log this Order");

        System.out.println("\n\nlogging the Fatal message") ;
        log.logMessage(LogType.FATAL, "Log this server failure of application shoping cart");

        System.out.println("\n\nlogging the Error message") ;
        log.logMessage(LogType.ERROR, "Log this failed to process Checkout");
        return ; 
    }
}