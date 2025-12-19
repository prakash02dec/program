package WeatherObservable ; 
import WeatherObserver.WeatherObserver ;

public interface WeatherObservable {
    void addObserver(WeatherObserver observer) ; 
    void removeObserver(WeatherObserver observer) ; 
    void notifyObservers() ; 
    void updateWeather(int temp, int windSpeed, int humidity) ; 
    void printReport() ; 
}