package shoppingCart;
import product.*;
import product.coupon.*;

import java.util.*;

public class Cart {
    ArrayList<Product> products;

    public Cart() {
        products = new ArrayList<>();
    }
    public void addProduct(Product product) {
        Product finalProduct = new ItemTypeCoupon( new PercentageCoupon(product, 20), 10) ;
        System.out.println("Final price for " + product.getName() + " : " + finalProduct.getPrice()) ;
        products.add(finalProduct);
    }

    public double getTotalPrice() {
        double total = 0.0;
        for(Product product : products) {
            total += product.getPrice();
        }
        return total;
    }

}
