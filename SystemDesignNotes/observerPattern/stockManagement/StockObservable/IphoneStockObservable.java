package StockObservable ; 

import StockObserver.StockObserver ;
import java.util.* ; 

public class IphoneStockObservable implements StockAvailabilityObservable {
    private final ArrayList<StockObserver>  observer ; 
    private  int quantity ; 
    private final String model ; 
    private final int productId ; 

    public IphoneStockObservable(){
        model = "Iphone18" ; 
        observer = new ArrayList<StockObserver> () ; 
        productId = 1010010 ; 
        quantity = 0 ; 
    }

    @Override
    public void addObserver(StockObserver obs){
        observer.add(obs) ;
    }

    @Override
    public void removeObserver(StockObserver obj){
        for(StockObserver obs : observer){
            if(obs == obj){
                observer.remove(obj) ;
                return ; 
            } 
        }

        return ; 
    }


    @Override
    public void notifyObserver(){
        for(StockObserver obs : observer){
            obs.update(model + " is in stock and quantity is " + quantity + " and product id is " + productId) ; 
        }
    }


    @Override
    public void reStock(int quantity){
        this.quantity += quantity ; 
        if(this.quantity > 0){
            notifyObserver() ; 
        }
    }

    @Override
    public boolean purchase(){
        if(quantity > 0){
            quantity--  ; 
            return true ; 
        }
        System.out.println(model +" NOT IN STOCK") ;
        return false ; 
    }

    public int getProductId() {
        return productId;
    }
}