package StockObserver ; 

import StockObservable.StockAvailabilityObservable ; 

public class PushNotification implements StockObserver {
    public final String UserID ; 

    public PushNotification(String UserID){
        this.UserID = UserID ; 
    }

    @Override
    public void update(String status) {
        System.out.println("\nHii "+ UserID + ":" + status) ; 
    }
    
    @Override
    public String getObserverType() {
        return "push" ;
    }

    @Override
    public String getUserID() {
        return UserID ; 
    } 

    public void buy(StockAvailabilityObservable stock){
        if(stock.purchase()){
            System.out.println("Buyed the Iphone") ;
            stock.removeObserver(this) ;
        }else{
            System.out.println("Unable to buy the phone because not in stock") ; 
            stock.addObserver(this) ;
        }
    }
}