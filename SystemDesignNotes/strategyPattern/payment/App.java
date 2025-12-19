import PaymentStrategy.* ; 
import Shopping.* ; 

public class App{
    public static void main(String[] args){
        PaymentStrategy payment = new CardPaymentStrategy("1234-5678-1234-7890") ;
        ShoppingCart cart = new ShoppingCart(payment) ;
        cart.buy(1000) ;
        payment = new UpiPaymentStrategy("1234@pingpay") ;
        cart.setPaymentMethod(payment) ;
        cart.buy(10000) ; 
        return ;
    }
}