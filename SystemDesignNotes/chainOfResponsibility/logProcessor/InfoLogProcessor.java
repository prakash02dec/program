package logProcessor ; 

public class InfoLogProcessor extends LogProcessor {
    public InfoLogProcessor(LogProcessor next){
        super(LogType.INFO, next) ;
    }
    
    public void print(String message){
        System.out.println("[INFO] : " + message) ; 
    }

    @Override 
    public void logMessage(LogType type , String message){
        if(type.getLevel() > LogType.FATAL.getLevel()) 
            throw new IllegalArgumentException("Unknown log level is being called") ;

        super.logMessage(type, message) ;
    }
}
