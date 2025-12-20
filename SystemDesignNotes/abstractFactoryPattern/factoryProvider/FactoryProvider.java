package factoryProvider ;
import carProduction.* ; 

public class FactoryProvider {
    public static CarProduction getProduction(String brand, FactoryType type){
        if(type == null) return null ; 

        switch(type){
            case PREMUIM :
            case LUXURY :
                return new LuxuryCarProduction(brand) ;
            case ECONOMY :
                return new EconomyCarProduction(brand) ;
            default :
                throw new IllegalArgumentException("Type is not define") ;
        }
    }
}