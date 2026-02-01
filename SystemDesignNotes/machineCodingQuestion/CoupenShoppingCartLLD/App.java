import product.Product;
import product.item.* ; 
import shoppingCart.*;

public class App {
    public static void main(String args[]) {
        Product smartdesk = new Desk("Sleeping company smart desk", 18000) ;
        System.out.println("Price of smart desk : " + smartdesk.getPrice()) ;
        Product monitor = new Monitor("samsung Odyssy monitor", 21000) ;
        System.out.println("Price of monitor : " + monitor.getPrice()) ;
        Product mangoJuice = new Juice("Mango Juice", 150) ;
        System.out.println("Price of mango juice : " + mangoJuice.getPrice()) ;
        Product chair = new Chair("Office Chair", 5000) ;
        System.out.println("Price of chair : " + chair.getPrice()) ;
        Product poloTshirt = new Tshirts("Polo Tshirt", 1200) ;
        System.out.println("Price of polo tshirt : " + poloTshirt.getPrice()) ;

        Cart cart = new Cart() ;
        cart.addProduct(smartdesk) ;
        cart.addProduct(monitor) ;
        cart.addProduct(mangoJuice) ;
        cart.addProduct(chair) ;
        cart.addProduct(poloTshirt) ;
        System.out.println("Total cart value : " + cart.getTotalPrice()) ;

    }   
}
