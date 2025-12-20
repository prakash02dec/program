package carProduction ;

import carExterior.* ; 
import carInterior.* ; 

public class LuxuryCarProduction extends CarProduction {
    public LuxuryCarProduction(String brand){
        super(brand) ;
    }

    @Override
    CarExterior createCarExterior(){
        return new LuxuryCarExterior() ;
    }

    @Override
    CarInterior createCarInterior(){
        return new LuxuryCarInterior() ; 
    }
}