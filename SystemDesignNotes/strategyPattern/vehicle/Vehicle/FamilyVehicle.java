package Vehicle ; 

import DriveStrategy.DriveStrategy ; 
 
public class FamilyVehicle extends Vehicle {
    public FamilyVehicle(DriveStrategy driveStrategyObj){
        super(driveStrategyObj) ;
        this.vehicleType = VehicleType.FAMILY ; 
    }
}