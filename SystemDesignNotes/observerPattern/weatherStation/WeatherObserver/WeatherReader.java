package WeatherObserver ;

import WeatherObservable.WeatherObservable ;
public class WeatherReader implements WeatherObserver {
    private WeatherObservable observable ; 
    public WeatherReader(WeatherObservable observable){
        this.observable = observable ; 
        observable.addObserver(this) ;
    }

    @Override
    public void update(){
        System.out.println("WEATHER READING") ; 
        observable.printReport() ; 
    }
}