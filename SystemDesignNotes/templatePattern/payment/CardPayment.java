package payment;

public class CardPayment extends PaymentFlow {
    @Override
    public void createAndValidatePayment(){
        System.out.println("Creating and validating card payment");
    }
    @Override
    public void authorizePayment(){
        System.out.println("Authorizing card payment");
    }
    @Override
    public void authenticatePayment(){
        System.out.println("Authenticating card payment");
    }
    @Override
    public void capturePayment(){
        System.out.println("Capturing card payment");
    }
}
