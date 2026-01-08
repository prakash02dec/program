package commands ; 
import airConditioner.* ; 

public class SetTemperatureCommand implements Command {
    int previousState ; 
    int setTemp ; 
    AirConditioner obj ; 

    public SetTemperatureCommand(AirConditioner ac, int set){
        obj = ac ; 
        previousState = obj.getTemperature() ; 
        setTemp = set ; 
    }

    @Override
    public void execute(){
        System.out.println("Setting temperature to " + setTemp) ; 
        previousState = obj.getTemperature(); 
        obj.setTemperature(setTemp) ; 
    }
    @Override
    public void undo(){
        System.out.println("Undoing set temperature to " + previousState) ; 
        obj.setTemperature(previousState) ;
    }
}