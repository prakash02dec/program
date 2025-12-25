package trafficLight ; 
import trafficLightState.* ; 

public interface TrafficLight {
    void setState(TrafficLightState state) ; 
    void change() ;
}