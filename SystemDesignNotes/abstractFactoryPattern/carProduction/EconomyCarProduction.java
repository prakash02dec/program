package carProduction ;

import carExterior.* ; 
import carInterior.* ; 

public class EconomyCarProduction extends CarProduction {
    public EconomyCarProduction(String brand){
        super(brand) ;
    }

    @Override
    CarExterior createCarExterior(){
        return new EconomyCarExterior() ;
    }

    @Override
    CarInterior createCarInterior(){
        return new EconomyCarInterior() ; 
    }
}