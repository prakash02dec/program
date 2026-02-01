package warehouse.SelectionStrategy;
import java.util.*;

import utils.Address;
import warehouse.*;

public interface SelectionStrategy {
    public Warehouse selectWarehouse(Address customerAddress, ArrayList<Warehouse> warehouses);
}   
