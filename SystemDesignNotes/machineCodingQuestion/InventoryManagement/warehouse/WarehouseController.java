package warehouse;
import java.util.* ;
import warehouse.SelectionStrategy.* ; 
import utils.Address;

public class WarehouseController {
    // This class will manage multiple warehouses and implement selection strategies
    static ArrayList<Warehouse> warehouses = new ArrayList<>() ;
    SelectionStrategy selectionStrategy ;

    public WarehouseController(){
        this.selectionStrategy = new NearestStrategy();
    }
    public void addWarehouse( Warehouse wh ){
        warehouses.add(wh) ;
    }
    public ArrayList<Warehouse> getAllWarehouses(){
        return warehouses ;
    }
    public void setSelectionStrategy( SelectionStrategy strategy ){
        this.selectionStrategy = strategy ;
    }
    public Warehouse selectWarehouse( Address customerAddress ){
        return this.selectionStrategy.selectWarehouse( customerAddress , warehouses ) ;
    }

}