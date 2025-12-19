package StockObserver ; 

import StockObservable.StockAvailabilityObservable ; 

public interface StockObserver {
    void update(String status) ; 
    String getObserverType() ; 
    String getUserID() ; 
    void buy(StockAvailabilityObservable stock) ; 
}