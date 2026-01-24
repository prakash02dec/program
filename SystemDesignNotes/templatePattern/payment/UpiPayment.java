package payment;

public class UpiPayment extends PaymentFlow {
    @Override
    public void createAndValidatePayment(){
        System.out.println("Creating and validating upi payment");
    }
    @Override
    public void authorizePayment(){
        System.out.println("Authorizing upi payment");
    }
    @Override
    public void authenticatePayment(){
        System.out.println("Authenticating upi payment");
    }
    @Override
    public void capturePayment(){
        System.out.println("Capturing upi payment");
    }
}