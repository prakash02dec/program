package product.coupon;
import product.*;

public abstract class Coupon extends Product {
    protected int discountPercentage ;
    Product product ; 
    
    public Coupon(Product product, int discountPercentage) {
        this.product = product;
        this.discountPercentage = discountPercentage;
    }

    public int getDiscountPercentage() {
        return discountPercentage;
    }
}
