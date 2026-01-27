package instrument.model;

public class InstrumentDoa {
    public InstrumentType type ;   
    public int instrumentId ; 
    public int userId ;
    public String cardNumber ; 
    public String cvv ; 
    public String accountNo ; 
    public String ifsc ; 

    public InstrumentType getType() {
        return type;
    }
    public void setType(InstrumentType type) {
        this.type = type;
    }
    public int getInstrumentId() {
        return instrumentId;
    }
    public void setInstrumentId(int instrumentId) {
        this.instrumentId = instrumentId;
    }
    public int getUserId() {
        return userId;
    }
    public void setUserId(int userId) {
        this.userId = userId;
    }
    public String getCardNumber() {
        return cardNumber;
    }
    public void setCardNumber(String cardNumber) {
        this.cardNumber = cardNumber;
    }
    public String getCvv() {
        return cvv;
    }
    public void setCvv(String cvv) {
        this.cvv = cvv;
    }
    public String getAccountNo() {
        return accountNo;
    }
    public void setAccountNo(String accountNo) {
        this.accountNo = accountNo;
    }
    public String getIfsc() {
        return ifsc;
    }
    public void setIfsc(String ifsc) {
        this.ifsc = ifsc;
    }

}
