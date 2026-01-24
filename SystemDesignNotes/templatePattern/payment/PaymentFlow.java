package payment;

public abstract class PaymentFlow {
    abstract public void createAndValidatePayment() ;
    abstract public void authorizePayment() ;
    abstract public void authenticatePayment() ;
    abstract public void capturePayment() ;
    public void initiatePayment(){
        System.out.println("Initiating payment flow");
        createAndValidatePayment();
        authorizePayment();
        authenticatePayment();
        capturePayment();
    }
    public void refundPayment(){
        System.out.println("Refund payment");
    }
    public void cancelPayment(){
        System.out.println("Cancel payment");
    }
}