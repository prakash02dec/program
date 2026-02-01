package product.item;

import product.Product;
import product.ProductType;

public class Chair extends Product {
    public Chair(String name, double price) {
        super(ProductType.FURNITURE, name, price);
    }

    @Override
    public double getPrice() {
        return price;
    }
}