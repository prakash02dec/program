package logProcessor ; 

public abstract class LogProcessor {

    public final static int INFO = 1 ;
    public final static int DEBUG = 2 ;
    public final static int ERROR = 3 ;
    public final static int FATAL = 4 ;

    private int level ; 
    private LogProcessor nextProcessor ; 

    public LogProcessor(int level, LogProcessor next){
        this.level = level; 
        this.nextProcessor = next ; 
    }
    
    public abstract void print(String message) ;
    public abstract String getType() ;

    public void logMessage(int level, String message){
        System.out.println(getType() + " : Processing the log " ) ; 

        if(this.level < level){
            if(nextProcessor != null )
                nextProcessor.logMessage(level, message);
            
            return ;
        }
        print(message) ; 
    }
    
}