package Pizza ;

public class PeppyPaneerPizza implements Pizza{
    @Override
    public String getDescription(){
        return "Peppy Paneer Pizza" ;
    }

    @Override
    public int getCost(){
        return 150 ; 
    }
}