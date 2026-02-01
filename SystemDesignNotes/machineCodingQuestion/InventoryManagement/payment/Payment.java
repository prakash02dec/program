package payment;

import java.util.Random;

public class Payment {
    public int paymentId ; 
    public String paymentType ;
    public double amount ;
    public Payment(String paymentType, double amount){
        this.paymentId = new Random().nextInt(100000-10000) + 10000 ;
        this.paymentType = paymentType ;
        this.amount = amount ;
    }

    public int getPaymentId() {
        return paymentId;
    }
    public String getPaymentType() {
        return paymentType;
    }
    public double getAmount() {
        return amount;
    }
}
