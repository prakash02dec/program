
import remote.* ; 
import commands.* ; 
import airConditioner.* ; 


public class App {
    public static void main(String[] args) {
        AirConditioner ac = new AirConditioner() ; 
        RemoteController remote = new RemoteController() ; 
        remote.setCommand(new TurnOnCommand(ac)) ; 
        remote.pressButton() ; 
        remote.setCommand(new TurnOffCommand(ac)) ; 
        remote.pressButton() ; 
        remote.setCommand(new SetTemperatureCommand(ac, 20)) ; 
        remote.pressButton() ; 
        remote.setCommand(new SetTemperatureCommand(ac, 26)) ;
        remote.pressButton() ; 
        remote.undo() ; 
        remote.undo() ; 
        remote.undo() ; 
        remote.undo() ; 
    }
}
