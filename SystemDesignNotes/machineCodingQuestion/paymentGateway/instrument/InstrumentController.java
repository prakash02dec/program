package instrument;
import instrument.service.*;
import instrument.model.*;
import java.util.* ; 

public class InstrumentController {
    public  InstrumentDoa addInstrument(InstrumentDoa doa) {
        InstrumentService src = InstrumentServiceFactory.getInstrumentService(doa.getType()) ;
        return src.addInstrument(doa) ;
    }

    public  ArrayList<InstrumentDoa> getByUserId(int userId) {
        InstrumentService card = InstrumentServiceFactory.getInstrumentService(InstrumentType.CARD) ;
        InstrumentService nb = InstrumentServiceFactory.getInstrumentService(InstrumentType.BANK) ;
        ArrayList<InstrumentDoa> list = card.getByUserId(userId) ;
        list.addAll(nb.getByUserId(userId)) ;
        return list;
    }

    public  InstrumentDoa getByInstrumentId(int userId, int instrumentId) {
        ArrayList<InstrumentDoa> all = getByUserId(userId) ;
        for(InstrumentDoa inst : all){
            if(inst.getInstrumentId() == instrumentId){
                return inst ; 
            }
        }
        return null ;
    }

}
