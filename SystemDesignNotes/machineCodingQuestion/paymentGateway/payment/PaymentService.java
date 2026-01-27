package payment;
import payment.processor.*;
import instrument.model.InstrumentType;
import payment.model.*;

public class PaymentService {

    public PaymentDao payment(PaymentDao dao){
        Processor paymentProcessor ;

        switch (dao.getSenderInstrument().getType()) {
            case InstrumentType.BANK:
                paymentProcessor = new BankProcessor() ;             
                dao = paymentProcessor.process(dao) ;
                dao = paymentProcessor.autoCapture(dao.getPaymentId()) ;
                return dao ; 
            case InstrumentType.CARD:
                paymentProcessor = new CardProcessor() ;             
                dao = paymentProcessor.process(dao) ;
                dao = paymentProcessor.autoCapture(dao.getPaymentId()) ;
                return dao ; 
            default:
                return null ;
        }

    }

}
