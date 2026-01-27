package payment.model;

import instrument.model.*;

public class Payment {
    int paymentId ; 
    InstrumentDoa senderInstrument ; 
    InstrumentDoa receiverInstrument ; 
    int amount ; 
    PaymentStatus status ;
    PaymentType type ; 

    public int getPaymentId() {
        return paymentId;
    }
    public void setPaymentId(int paymentId) {
        this.paymentId = paymentId;
    }
    public InstrumentDoa getSenderInstrument() {
        return senderInstrument;
    }
    public void setSenderInstrument(InstrumentDoa senderInstrument) {
        this.senderInstrument = senderInstrument;
    }
    public InstrumentDoa getReceiverInstrument() {
        return receiverInstrument;
    }
    public void setReceiverInstrument(InstrumentDoa receiverInstrument) {
        this.receiverInstrument = receiverInstrument;
    }
    public int getAmount() {
        return amount;
    }
    public void setAmount(int amount) {
        this.amount = amount;
    }
    public PaymentStatus getStatus() {
        return status;
    }
    public void setStatus(PaymentStatus status) {
        this.status = status;
    }
    public PaymentType getType() {
        return type;
    }
    public void setType(PaymentType type) {
        this.type = type;
    } 
    
}
