package instrument.service;
import instrument.model.*;
import java.util.* ; 

public abstract class InstrumentService {
    static Map<Integer, ArrayList<Instrument>> userInstrumentMap = new HashMap<>() ; 

    public InstrumentService(){
    }

    public abstract InstrumentDoa addInstrument(InstrumentDoa doa) ; 
    public abstract ArrayList<InstrumentDoa> getByUserId(int userId) ; 

}
