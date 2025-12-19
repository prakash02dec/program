package PaymentStrategy ; 

public class NbPaymentStrategy implements PaymentStrategy {
    private String email ; 
    
    public NbPaymentStrategy(String email){
        this.email = email ; 
    }

    @Override
    void pay(double amount){
        System.out.println("Paying " + amount + " with NetBanking method via email acount : " + email) ;
    }
}