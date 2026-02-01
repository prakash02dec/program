package product.item;

import product.Product;
import product.ProductType;

public class Desk extends Product {
    public Desk(String name, double price) {
        super(ProductType.FURNITURE, name, price);
    }

    @Override
    public double getPrice() {
        return price;
    }
}