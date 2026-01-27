package payment.processor;
import payment.model.* ; 
import java.util.* ; 


public abstract class Processor{
    static Map< Integer, Payment>  payments = new HashMap<>() ; 

    public Processor(){
       
    }

    public abstract Payment validateAndCreate(PaymentDao doa) ;
    public abstract void initiate(int paymentId) ; 
    public abstract void authenticate(int paymentId) ; 
    public abstract void authorized(int payId) ;
    public abstract void capture(int payId) ;


    public PaymentDao getByPaymentId(int payId){
        return paymentObjToDoa(payments.get(payId)) ;
    }


    public PaymentDao process(PaymentDao doa){
        Payment pay = validateAndCreate(doa) ; 
        initiate(pay.getPaymentId());
        authenticate(pay.getPaymentId()) ;
        return paymentObjToDoa(pay); 
    }


    public PaymentDao autoCapture(int payId){
        authorized(payId);
        capture(payId);

        return getByPaymentId(payId ) ;
    }

    public PaymentDao paymentObjToDoa(Payment pay){

        PaymentDao dao = new PaymentDao();
        dao.setPaymentId(pay.getPaymentId());
        dao.setAmount(pay.getAmount());
        dao.setStatus(pay.getStatus());
        dao.setType(pay.getType());
        dao.setSenderInstrument(pay.getSenderInstrument());
        dao.setReceiverInstrument(pay.getReceiverInstrument());
        return dao;
    }
}