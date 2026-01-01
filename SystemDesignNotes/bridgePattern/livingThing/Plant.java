package livingThing ; 
import breathingProcess.* ; 

public class Plant extends LivingThing{

    public Plant(BreathingProcess obj) {
       super(obj) ;
    }

    @Override
    public void breath(){
        breathingProcess.breath() ; 
    }
}