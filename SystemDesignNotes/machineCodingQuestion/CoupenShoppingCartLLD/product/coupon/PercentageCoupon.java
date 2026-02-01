package product.coupon;
import product.*;

public class PercentageCoupon extends Coupon {

    public PercentageCoupon(Product product, int discountPercentage) {
        super(product, discountPercentage);
    }

    @Override
    public double getPrice() {
        return product.getPrice() * (1 - discountPercentage / 100.0);
    }
}
