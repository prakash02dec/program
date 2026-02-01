import java.util.* ;

import user.*;
import warehouse.*;
import utils.Address;
import product.*;
import cart.* ;
import order.*; 

public class App {
    UserController userController ;
    WarehouseController warehouseController ;
    OrderController orderController ;
    public App(){
        this.userController = new UserController() ;
        this.warehouseController = new WarehouseController() ;
        this.orderController = new OrderController() ;
    }
    public static void main(String[] args) {
        App app = new App();
        app.setup() ; 
        app.demoRun() ; 
    }

    public void setup(){
        // create users
        User user1 = new User("Alice", "alice@example.com", "1234567890", new Address("CityA, StateA, 12345"));
        this.userController.addUser(user1);
        User user2 = new User("Bob", "bob@example.com", "0987654321", new Address("CityB, StateB, 54321"));
        this.userController.addUser(user2);

        // create warehouses
        Warehouse wh1 = new Warehouse("Warehouse1", new Address("CityA, StateA, 12385"));
        this.warehouseController.addWarehouse(wh1);
        Warehouse wh2 = new Warehouse("Warehouse2", new Address("CityB, StateB, 54320"));
        this.warehouseController.addWarehouse(wh2); 
        Inventory inventory1 = wh1.getInventory();

        // fill inventory of warehouses
        ProductStock pepsiStock = new ProductStock( "Pepsis", 1000.0 ) ;
        ProductStock shoeStock = new ProductStock( "Shoes", 500.0 ) ;
        for(int i = 0; i < 10; i++){
            Product pepsi = new Product("Pepsi" + i);
            pepsiStock.addProduct(pepsi);
        }
        inventory1.addProductStock(pepsiStock);
        for(int i = 0; i < 5; i++){
            Product shoe = new Product("Shoe" + i);
            shoeStock.addProduct(shoe);
        }
        inventory1.addProductStock(shoeStock);
        wh1.display() ;

        Inventory inventory2 = wh2.getInventory();
        ProductStock pepsiStock2 = new ProductStock( "Pepsis", 1000.0 ) ;
        ProductStock shoeStock2 = new ProductStock( "Shoes", 500.0 ) ;
        for(int i = 0; i < 10; i++){
            Product pepsi = new Product("Pepsi" + i);
            pepsiStock2.addProduct(pepsi);
        }
        inventory2.addProductStock(pepsiStock2);
        for(int i = 0; i < 5; i++){
            Product shoe = new Product("Shoe" + i);
            shoeStock2.addProduct(shoe);
        }
        inventory2.addProductStock(shoeStock2  );
        wh2.display();
    }


    public void demoRun(){
        // select warehouse for user1
        User user1 = this.userController.getByUserId(1) ;
        
        Warehouse nearestWarehouse = this.warehouseController.selectWarehouse( user1.getAddress() ) ;
        System.out.println("\nSelected warehouse for user " + user1.getName() + " is " + nearestWarehouse.getName() ) ;
        
        // add stock to user1's cart
        Cart user1Cart = user1.getCart() ;
        ProductStock pepsiStock = nearestWarehouse.getInventory().getProductStockByName("Pepsis") ;
        user1Cart.addProductStock( pepsiStock, 3) ;
        ProductStock shoeStock = nearestWarehouse.getInventory().getProductStockByName("Shoes") ;
        user1Cart.addProductStock(shoeStock, 6);
        user1.viewCart();
        Order order1 = this.orderController.processCheckout( user1, nearestWarehouse ) ;

        System.out.println("Order placed successfully: ") ;
        System.out.println(order1) ;
        System.err.println();
        nearestWarehouse.display() ;
        // checkout 
    }
}
