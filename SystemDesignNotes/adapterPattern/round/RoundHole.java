package round ; 

public class RoundHole { 
    double radius ; 
    public RoundHole(double r){
        radius = r ; 
    }

    public double getRadius(){
        return this.radius ; 
    }

    public boolean isfit(RoundPeg rp){
        if(radius >= rp.getRadius()){
            
            return true ; 
        }
        return false ; 
    }

}