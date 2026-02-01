package product.item;
import product.* ; 

public class Tshirts extends Product {
    public Tshirts(String name, double price) {
        super(ProductType.CLOTHING, name, price);
    }

    @Override
    public double getPrice() {
        return price;
    }
    
}
