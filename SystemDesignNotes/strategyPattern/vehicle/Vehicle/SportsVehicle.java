package Vehicle ; 

import DriveStrategy.DriveStrategy ;

public class SportsVehicle extends Vehicle{
    public SportsVehicle(DriveStrategy driveStrategyObj){
        super(driveStrategyObj) ;
        this.vehicleType = VehicleType.SPORTS ;
    }
}