import payment.* ; 
public class App {
    public static void main(String[] args) {
        PaymentFlow cardPayment = new CardPayment();
        cardPayment.initiatePayment();
        cardPayment.refundPayment();
        System.out.println("--------------------------------");
        PaymentFlow upiPayment = new UpiPayment();
        upiPayment.initiatePayment();
    }
}
