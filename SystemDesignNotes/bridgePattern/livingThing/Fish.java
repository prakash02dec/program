package livingThing ; 
import breathingProcess.* ; 

public class Fish extends LivingThing{

    public Fish(BreathingProcess obj) {
       super(obj) ;
    }

    @Override
    public void breath(){
        breathingProcess.breath() ; 
    }
}