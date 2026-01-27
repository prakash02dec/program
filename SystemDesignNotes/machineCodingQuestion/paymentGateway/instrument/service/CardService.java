package instrument.service;
import instrument.model.*;
import java.util.*;

public class CardService extends InstrumentService {
    @Override 
    public  InstrumentDoa addInstrument(InstrumentDoa doa) {
        CardInstrument card = new CardInstrument() ; 
        card.setInstrumentId((int) new Random().nextInt(1000-100)+100);
        card.setUserId(doa.getUserId());
        card.setType(InstrumentType.CARD);
        card.setCardNumber(doa.getCardNumber()) ;
        card.setCvv(doa.getCvv());
        ArrayList<Instrument> instruments = userInstrumentMap.get(doa.getUserId());
        if(instruments == null){
            instruments = new ArrayList<>() ; 
            userInstrumentMap.put(doa.getUserId(), instruments) ;
        }
        instruments.add(card);

        return instrumentObjToDoa(card) ; 
    } 

    @Override 
    public  ArrayList<InstrumentDoa> getByUserId(int userId) {
        ArrayList<Instrument> userInstrument = userInstrumentMap.get(userId) ;
        ArrayList<InstrumentDoa>  res = new ArrayList<>(); 
        if(userInstrument != null) {
            for(Instrument ins : userInstrument){
                if(ins.getType() == InstrumentType.CARD) 
                        res.add(instrumentObjToDoa((CardInstrument)ins)) ;
            }
        }
        return res ; 
    }

    private InstrumentDoa instrumentObjToDoa(CardInstrument card){
        InstrumentDoa doa = new InstrumentDoa() ; 
        doa.setInstrumentId(card.getInstrumentId()) ;
        doa.setUserId(card.getUserId());
        doa.setType(card.getType());
        doa.setCardNumber(card.getCardNumber());
        doa.setCvv(card.getCvv());
        return doa ; 
    }
}
