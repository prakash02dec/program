package warehouse;
import utils.* ;
import java.util.* ;
public class Warehouse {
    static int idCounter = 1000 ;
    public int warehouseId ;
    public String name ; 
    public  Inventory inventory ;
    public Address address ; 

    public Warehouse(String name, Address address){
        this.name = name ;
        this.address = address ;
        this.inventory = new Inventory() ; 
        this.warehouseId = idCounter++ ;
    }

    public Address getAddress(){
        return this.address ; 
    }

    public Inventory getInventory(){
        return this.inventory ; 
    }

    public String getName(){
        return this.name ;
    }

    public void updateInventoryAfterOrder( Map<Integer, Integer> productStockIdToCountMap ){
        this.inventory.updateAfterOrder(productStockIdToCountMap) ;
    }

    public void display(){
        System.out.println("\nWarehouse ID: " + this.warehouseId + ", Name: " + this.name + ", Address: " + this.address );
        System.out.println("Inventory: ");
        this.inventory.display() ; 
        return ;
    }
    
}
