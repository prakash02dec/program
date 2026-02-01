package warehouse.SelectionStrategy;

import utils.Address;
import warehouse.* ;
import java.util.* ; 

public class NearestStrategy implements SelectionStrategy {
    @Override
    public Warehouse selectWarehouse(Address customerAddress, ArrayList<Warehouse> warehouses)  {
        int minDistance = Integer.MAX_VALUE;
        Warehouse nearestWarehouse = null;
        for (Warehouse warehouse : warehouses) {
            int distance = Math.abs(warehouse.getAddress().getPinCode() - customerAddress.getPinCode());
            if (distance < minDistance) {
                minDistance = distance;
                nearestWarehouse = warehouse;
            }
        }
        return nearestWarehouse;
    }
}
