package logProcessor ; 

public class FatalLogProcessor extends LogProcessor {
    public FatalLogProcessor(LogProcessor next){
        super(FATAL, next) ;
    }
    
    public void print(String message){
        System.out.println("[FATAL] : " + message) ; 
    }
    public String getType(){
        return "FATAL" ; 
    }
}