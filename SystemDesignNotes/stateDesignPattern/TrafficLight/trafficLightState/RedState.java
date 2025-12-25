package trafficLightState ; 

import trafficLight.* ; 

public class RedState implements TrafficLightState {
    @Override 
    public void action(TrafficLight obj){
        // set next color and stop displaying current color ; 
        System.out.println("Changing from RED to YELLOW") ;
        obj.setState(new YellowState()) ;
    }
}