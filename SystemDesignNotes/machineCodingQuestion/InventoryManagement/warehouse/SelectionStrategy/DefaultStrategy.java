package warehouse.SelectionStrategy;
import java.util.* ;
import utils.Address;
import warehouse.* ;
public class DefaultStrategy implements SelectionStrategy {
    @Override
    public Warehouse selectWarehouse(Address customerAddress, ArrayList<Warehouse> warehouses) {
        return warehouses.get(0); // Default strategy returns the first warehouse
    }
}