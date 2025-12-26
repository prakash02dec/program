package adapter ; 
import square.*; 
import round.* ; 

public class SquarePegAdapter  extends RoundPeg {
    SquarePeg obj ; 
    public SquarePegAdapter(SquarePeg sp){
        obj = sp ; 
    }

    @Override
    public double getRadius(){
        return obj.getSide()/Math.sqrt(2) ;
    }

}