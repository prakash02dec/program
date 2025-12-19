package Shopping ; 
import PaymentStrategy.* ; 

public class ShoppingCart {
    PaymentStrategy paymentStrategy ; 

    public ShoppingCart(PaymentStrategy paymentStrategyObj){
        this.paymentStrategy = paymentStrategyObj ; 
    }

    public void setPaymentMethod(PaymentStrategy paymentStrategyObj){
        this.paymentStrategy = paymentStrategyObj ; 
    }
    
    public void buy(double amount){
        paymentStrategy.pay(amount);
    }
}