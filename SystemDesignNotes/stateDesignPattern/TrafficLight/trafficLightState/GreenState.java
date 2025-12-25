package trafficLightState ; 
import trafficLight.* ;

public class GreenState implements TrafficLightState {
    @Override 
    public void action(TrafficLight obj){
        System.out.println("Changing from GREEN to RED") ;
        obj.setState(new RedState()) ;
    }
}