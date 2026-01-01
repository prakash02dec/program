package livingThing ; 
import breathingProcess.* ; 

public class Dog extends LivingThing{

    public Dog(BreathingProcess obj) {
       super(obj) ;
    }

    @Override
    public void breath(){
        breathingProcess.breath() ; 
    }
}