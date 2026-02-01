package product.item;

import product.Product;
import product.ProductType;

public class Monitor extends Product {
    public Monitor(String name, double price) {
        super(ProductType.ELECTRONICS, name, price);
    }

    @Override
    public double getPrice() {
        return price;
    }
}
