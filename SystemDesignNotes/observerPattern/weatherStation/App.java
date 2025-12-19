import WeatherObserver.* ; 
import WeatherObservable.* ; 

public class App {
    public static void main(String[] args){
        WeatherObservable observable = new WeatherStation(100, 10, 101) ;
        WeatherObserver reader = new WeatherReader(observable) ;
        WeatherObserver forecaster = new WeatherForcaster(observable) ;

        observable.updateWeather(104, 100, 10) ;
        System.out.print("\n");
        observable.removeObserver(forecaster) ;
        observable.updateWeather(50, 50, 100) ;
        System.out.print("\n");
        observable.removeObserver(reader) ;
        
    }
}