package payment.processor;

import java.util.Random;

import payment.model.Payment;
import payment.model.PaymentDao;
import payment.model.PaymentStatus;
import payment.model.PaymentType;

public class BankProcessor  extends Processor{
    @Override
    public Payment validateAndCreate(PaymentDao doa) {

        // do bank some validation
        
        
        Payment pay = new Payment() ; 
        pay.setAmount(doa.getAmount());
        pay.setPaymentId((int) new Random().nextInt(1000-100)+100);
        pay.setReceiverInstrument(doa.getReceiverInstrument());
        pay.setSenderInstrument(doa.getReceiverInstrument());
        pay.setStatus(PaymentStatus.CREATED);
        pay.setType(PaymentType.NETBANKING);

        payments.put(pay.getPaymentId(), pay) ;


        System.out.println(" Bank Payment ValidateAndCreate step : " + pay.getPaymentId()) ;
        return pay ; 
    }

    @Override
    public  void initiate(int paymentId) {
        System.out.println("Bank Payment Initiated step : " + paymentId) ;
    }
    @Override
    public  void authenticate(int paymentId) {
        System.out.println("Bank Payment Payment Authenticated step : " + paymentId) ;
        payments.get(paymentId).setStatus(PaymentStatus.AUTHENTICATED);
    }
    @Override
    public  void authorized(int payId) {
        System.out.println("Bank Payment Payment authorized step : " + payId) ;
        payments.get(payId).setStatus(PaymentStatus.AUTHORIZED);
    }
    @Override
    public  void capture(int payId) {
        System.out.println("Bank Payment Payment capture step : " + payId) ;
        payments.get(payId).setStatus(PaymentStatus.SUCCESS);
    }
    
}
