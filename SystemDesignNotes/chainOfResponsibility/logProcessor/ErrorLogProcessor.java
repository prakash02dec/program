package logProcessor ; 

public class ErrorLogProcessor extends LogProcessor {
    public ErrorLogProcessor(LogProcessor next){
        super(ERROR, next) ;
    }
    
    public void print(String message){
        System.out.println("[ERROR] : " + message) ; 
    }
    public String getType(){
        return "ERROR" ; 
    }
}