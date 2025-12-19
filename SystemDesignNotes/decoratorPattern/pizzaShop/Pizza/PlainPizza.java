package Pizza ;

public class PlainPizza implements Pizza {
    @Override
    public String getDescription(){
        return "Plain Pizza" ;
    }

    @Override
    public int getCost(){
        return 100 ; 
    }
}