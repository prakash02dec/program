import trafficLight.* ; 
import trafficLightState.* ; 

public class App {
    public static void main(String args[]){
        TrafficLight trafficLight = new TrafficLightImp() ; 
        trafficLight.change() ;
        trafficLight.change() ;
        trafficLight.change() ;
        trafficLight.change() ;
        trafficLight.change() ;
        return ; 
    }
}