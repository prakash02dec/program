package remote ; 
import commands.* ; 
import java.util.* ; 
public class RemoteController { 
    Command command ; 
    Stack<Command> history ; 

    
    public RemoteController(Command com){
        command = com ; 
        history = new Stack<Command>() ; 
    }

    public RemoteController(){
        history = new Stack<Command>() ; 
    }

    public void setCommand(Command com){
        command = com ; 
    }
    
    public void pressButton(){
        command.execute() ; 
        history.add(command) ;
    }

    public void undo(){
        if(!history.isEmpty()){
            Command recent = history.pop() ; 
            recent.undo() ; 
        }
    }
}