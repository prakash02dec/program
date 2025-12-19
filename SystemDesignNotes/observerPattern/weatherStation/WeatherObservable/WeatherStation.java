package WeatherObservable ; 

import WeatherObserver.WeatherObserver ;
import java.util.* ;

public class WeatherStation implements WeatherObservable{
    private final ArrayList<WeatherObserver>  observers ; 
    private int temperature ; 
    private int windSpeed ; 
    private int humidity ; 
    
    public WeatherStation(int temp, int windSpeed, int humidity){
        this.temperature = temp ; 
        this.windSpeed = windSpeed ; 
        this.humidity = humidity ; 
        observers = new ArrayList<WeatherObserver> () ; 
    }

    @Override
    public void addObserver(WeatherObserver observer){
        observers.add(observer) ;
    }

    @Override
    public void removeObserver(WeatherObserver observer){
        observers.remove(observer) ; 
    }

    @Override
    public void notifyObservers(){
        for(WeatherObserver obs : observers){
            obs.update() ;
        }
    }

    @Override
    public void updateWeather(int temp, int windSpeed, int humidity){
        this.temperature = temp ; 
        this.windSpeed = windSpeed ; 
        this.humidity = humidity ; 
        notifyObservers() ; 
    }
    
    @Override 
    public void printReport(){
        System.out.println("temperature : " + temperature + " windSpeed : " + windSpeed + " humidity : " + humidity) ;
    }
}