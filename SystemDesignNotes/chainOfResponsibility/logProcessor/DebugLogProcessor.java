package logProcessor ; 

public class DebugLogProcessor extends LogProcessor {
    public DebugLogProcessor(LogProcessor next){
        super(LogType.DEBUG, next) ;
    }
    
    public void print(String message){
        System.out.println("[DEBUG] : " + message) ; 
    }
}