package WeatherObserver ;

import WeatherObservable.WeatherObservable ;
public class WeatherForcaster implements WeatherObserver {
    private WeatherObservable observable ; 
    public WeatherForcaster(WeatherObservable observable){
        this.observable = observable ; 
        observable.addObserver(this) ;
    }

    @Override
    public void update(){
        System.out.println("FORCASTING WEATHER") ; 
        observable.printReport() ; 
        System.out.println("temperature will be higher in the coming days. And there is high possiblity of loo.") ;
    }
}