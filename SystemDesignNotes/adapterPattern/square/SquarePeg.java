package square ;

public class SquarePeg{
    int side ; 
    
    public SquarePeg(int side){
        this.side = side ; 
    }
    
    public int getSquare(){
        return side*side ; 
    }

    public int getSide(){
        return side ; 
    }

}