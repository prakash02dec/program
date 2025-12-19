import StockObserver.* ; 
import StockObservable.* ; 

public class App {
    public static void main(String[] ars) { 
        StockObserver prakash_push = new PushNotification("Prakash") ;
        StockObserver rishabh_email = new EmailNotification("rishabh") ;
        StockObserver john_push = new PushNotification("john") ;
        StockObserver max_email = new EmailNotification("max") ;

        StockAvailabilityObservable iphone = new IphoneStockObservable() ; 

        prakash_push.buy(iphone) ; 
        max_email.buy(iphone);
        rishabh_email.buy(iphone); 

        iphone.reStock(5) ; 

        prakash_push.buy(iphone) ; 
        max_email.buy(iphone) ; 
        rishabh_email.buy(iphone) ;
        john_push.buy(iphone) ; 
        return ; 
    }
}