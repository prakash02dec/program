package PaymentStrategy ; 

public class UpiPaymentStrategy implements PaymentStrategy {
    private String vpa ; 
    public UpiPaymentStrategy(String vpa){
        this.vpa = vpa ; 
    }

    @Override
    public void pay(double amount){
        System.out.println("Paying " + amount + " with UPI method via vpa " + vpa) ;
    }
}