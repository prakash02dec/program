package Vehicle;

import DriveStrategy.DriveStrategy ;

public abstract class Vehicle {
    public DriveStrategy driveStrategy ;
    public VehicleType vehicleType ;

    public Vehicle(DriveStrategy  driveStrategyObj){
        this.driveStrategy = driveStrategyObj ; 
    }

    public void start(){
        System.out.println("\nStarting the " + vehicleType + " vehicle") ;
        driveStrategy.drive() ;
    }
}
