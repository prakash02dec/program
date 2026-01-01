package livingThing ; 
import breathingProcess.* ; 

public abstract class LivingThing {
    BreathingProcess breathingProcess  ; 

    public LivingThing(BreathingProcess obj) {
        breathingProcess = obj ;
    }

    public void breath(){
        breathingProcess.breath() ; 
    }
}