package trafficLight ; 
import trafficLightState.* ; 

public class TrafficLightImp implements TrafficLight {
    TrafficLightState state ; 
    public TrafficLightImp(){
        state = new RedState() ; 
    }
    @Override
    public void setState(TrafficLightState state){
        this.state = state ;
    }
    @Override
    public void change(){
        state.action(this) ; 
    }
}