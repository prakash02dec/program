import DriveStrategy.* ; 
import Vehicle.* ; 

public class App{
    public static void main(String[] args){
        Vehicle vehicle = new SportsVehicle(new SportsDriveStrategy() ) ;
        vehicle.start() ;
        vehicle = new FamilyVehicle(new NormalDriveStrategy()) ;
        vehicle.start() ; 
        HybridVehicle hybrid = new HybridVehicle(new ElectricDriveStrategy()) ;
        hybrid.start() ; 
        return ; 
    }
}
