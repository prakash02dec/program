package logProcessor ; 

public abstract class LogProcessor {

    private LogType type ; 
    private LogProcessor nextProcessor ; 

    public LogProcessor(LogType type, LogProcessor next){
        this.type = type; 
        this.nextProcessor = next ; 
    }
    
    public abstract void print(String message) ;

    public void logMessage(LogType type, String message){
        System.out.println(this.type.toString() + " : Processing the log " ) ; 

        if(this.type.getLevel() < type.getLevel()){
            if(nextProcessor != null )
                nextProcessor.logMessage(type, message);
            
            return ;
        }
        
        print(message) ; 
    }
    
}