package Vehicle ; 

import DriveStrategy.DriveStrategy ; 
 
public class HybridVehicle extends Vehicle {
    public HybridVehicle(DriveStrategy driveStrategyObj){
        super(driveStrategyObj) ;
        this.vehicleType = VehicleType.HYBRID ; 
    }
}