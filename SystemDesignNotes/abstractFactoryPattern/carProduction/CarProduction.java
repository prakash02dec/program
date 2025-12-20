package carProduction ; 
import carExterior.* ; 
import carInterior.* ; 

public abstract class CarProduction {
    private String brand ; 

    CarProduction(String brand){
        this.brand = brand ; 
    }

    abstract CarInterior createCarInterior() ;
    abstract CarExterior createCarExterior() ; 

    public void startProduction(){
        System.out.println(brand + " starting a car production");
        CarExterior exterior = createCarExterior() ;
        CarInterior interior = createCarInterior() ;

        exterior.addExteriorComponent() ; 
        interior.addInteriorComponent() ; 

        System.out.println(brand + " finishing a car production");
        return ; 
    }
}