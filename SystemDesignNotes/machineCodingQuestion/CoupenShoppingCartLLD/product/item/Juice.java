package product.item;

import product.Product;
import product.ProductType;

public class Juice extends Product {
    public Juice(String name, double price) {
        super(ProductType.GROCERY, name, price);
    }

    @Override
    public double getPrice() {
        return price;
    }
}

