package logProcessor ; 

public class InfoLogProcessor extends LogProcessor {
    public InfoLogProcessor(LogProcessor next){
        super(INFO, next) ;
    }
    
    public void print(String message){
        System.out.println("[INFO] : " + message) ; 
    }
    public String getType(){
        return "INFO" ; 
    }

    @Override 
    public void logMessage(int level , String message){
        if(level > FATAL) 
            throw new IllegalArgumentException("Unknown log level is being called") ;

        super.logMessage(level, message) ;
    }
}
