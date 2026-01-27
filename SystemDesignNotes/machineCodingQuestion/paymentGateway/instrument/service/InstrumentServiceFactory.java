package instrument.service;

import instrument.model.InstrumentType;

public class InstrumentServiceFactory {
    public static InstrumentService getInstrumentService(InstrumentType type){
        switch (type) {
            case InstrumentType.CARD:
                return new CardService() ; 
            case InstrumentType.BANK:
                return new BankService() ; 
            default:
                return null ; 
        }
    }
}
