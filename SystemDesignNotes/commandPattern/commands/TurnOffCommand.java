package commands ; 
import airConditioner.* ; 

public class TurnOffCommand implements Command {
    boolean previousState ; 
    AirConditioner obj ; 
    public TurnOffCommand(AirConditioner ac){
        obj = ac ; 
        previousState = obj.isOn() ; 
    }

    @Override
    public void execute(){
        System.out.println("Turning off the air conditioner") ; 
        previousState = obj.isOn() ; 
        obj.turnOff() ; 
    }
    @Override
    public void undo(){
        if(previousState){
            System.out.println("Undoing turn off the air conditioner") ; 
            obj.turnOn() ; 
        }
    }
}