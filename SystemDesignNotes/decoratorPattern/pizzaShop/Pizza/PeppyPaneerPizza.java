package Pizza ;

public class PeppyPaneerPizza implements Pizza{
    @Override
    public String getDescription(){
        return "Plain Pizza" ;
    }

    @Override
    public int getCost(){
        return 150 ; 
    }
}