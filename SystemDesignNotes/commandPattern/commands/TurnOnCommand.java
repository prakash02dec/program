package commands ; 
import airConditioner.* ; 

public class TurnOnCommand implements Command {
    boolean previousState ; 
    AirConditioner obj ; 
    public TurnOnCommand(AirConditioner ac){
        obj = ac ; 
        previousState = obj.isOn() ; 
    }
    @Override
    public void execute(){
        System.out.println("Turning on the air conditioner") ; 
        previousState = obj.isOn() ; 
        obj.turnOn() ; 
    }
    @Override
    public void undo(){
        if(!previousState){
            System.out.println("Undoing turn on the air conditioner") ; 
            obj.turnOff() ; 
        }
    }
}