package StockObserver ; 

import StockObservable.StockAvailabilityObservable ; 

public class EmailNotification implements StockObserver {
    public final String UserID ; 

    public EmailNotification(String UserID){
        this.UserID = UserID ; 
    }

    @Override
    public void update(String status) {
        System.out.println("\n") ;
        System.out.println("Dear "+ UserID + "\n" + status) ; 
    }
    
    @Override
    public String getObserverType() {
        return "email" ;
    }

    @Override
    public String getUserID() {
        return UserID ; 
    } 

    public void buy(StockAvailabilityObservable stock){
        if(stock.purchase()){
            System.out.println(UserID + " brought the Iphone" ) ;
            stock.removeObserver(this) ;
        }else{
            System.out.println("Unable to buy the phone because not in stock") ; 
            stock.addObserver(this) ;
        }
    }
}