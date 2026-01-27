package instrument.service;
import instrument.model.*;
import java.util.*;

public class BankService extends InstrumentService{

    @Override 
    public  InstrumentDoa addInstrument(InstrumentDoa doa) {
        BankInstrument bank = new BankInstrument() ; 
        bank.setInstrumentId((int) new Random().nextInt(1000-100)+100);
        bank.setUserId(doa.getUserId());
        bank.setType(InstrumentType.BANK);
        bank.setAccountNo(doa.getAccountNo());
        bank.setIfsc(doa.getIfsc());
        ArrayList<Instrument> instruments = userInstrumentMap.get(doa.getUserId());
        if(instruments == null){
            instruments = new ArrayList<>() ; 
            userInstrumentMap.put(doa.getUserId(), instruments) ;
        }
        instruments.add(bank);

        return instrumentObjToDoa(bank) ; 
    } 

    @Override 
    public  ArrayList<InstrumentDoa> getByUserId(int userId) {
        ArrayList<Instrument> userInstrument = userInstrumentMap.get(userId) ;
        ArrayList<InstrumentDoa>  res = new ArrayList<>(); 
        if(userInstrument != null) {
            for(Instrument ins : userInstrument){
                if(ins.getType() == InstrumentType.BANK) 
                        res.add(instrumentObjToDoa((BankInstrument)ins)) ;
            }
        }
        return res ; 
    }

    private InstrumentDoa instrumentObjToDoa(BankInstrument bank){
        InstrumentDoa doa = new InstrumentDoa() ; 
        doa.setInstrumentId(bank.getInstrumentId()) ;
        doa.setUserId(bank.getUserId());
        doa.setType(bank.getType());
        doa.setAccountNo(bank.getAccountNo());
        doa.setIfsc(bank.getIfsc());
        return doa ; 
    }
}
