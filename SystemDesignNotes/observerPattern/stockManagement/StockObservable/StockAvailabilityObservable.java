package StockObservable ;

import StockObserver.StockObserver ; 

public interface StockAvailabilityObservable {
    void addObserver(StockObserver obs) ;
    void removeObserver(StockObserver obs) ; 
    void notifyObserver() ; 
    void reStock(int quantity) ; 
    boolean purchase() ; 
}