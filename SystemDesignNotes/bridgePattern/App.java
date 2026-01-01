import breathingProcess.* ; 
import livingThing.* ; 

public class App {
    public static void main(String args[]){
        BreathingProcess lungs = new LungBreathing() ; 
        Dog dog = new Dog(lungs) ;
        dog.breath() ; 
        BreathingProcess gills = new GillBreathing() ; 
        Fish fish = new Fish(gills) ;
        fish.breath() ; 
    }
}