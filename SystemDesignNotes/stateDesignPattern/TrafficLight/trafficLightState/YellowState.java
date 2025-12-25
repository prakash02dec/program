package trafficLightState ; 
import trafficLight.* ; 

public class YellowState implements TrafficLightState {
    @Override
    public void action(TrafficLight obj){
        System.out.println("Changing from YELLOW to GREEN") ;
        obj.setState(new GreenState() ) ;
    }
}