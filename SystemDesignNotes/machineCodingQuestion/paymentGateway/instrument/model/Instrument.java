package instrument.model ; 

public abstract class Instrument {
    InstrumentType type ;   
    int instrumentId ; 
    int userId ;

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
    
}