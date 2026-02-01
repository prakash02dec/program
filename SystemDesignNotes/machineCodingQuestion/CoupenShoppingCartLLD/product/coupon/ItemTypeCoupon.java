package product.coupon;
import product.*;
import java.util.* ; 

public class ItemTypeCoupon extends Coupon {
    static ArrayList<ProductType> applicableItemTypes = new ArrayList<>(Arrays.asList(ProductType.ELECTRONICS, ProductType.FURNITURE));
    public ItemTypeCoupon(Product product, int discountPercentage) {
        super(product, discountPercentage);
    }

    @Override
    public double getPrice() {
        if(!applicableItemTypes.contains(product.getProductType())) {
            return product.getPrice() ;
        }
        return product.getPrice() * (1 - discountPercentage / 100.0);
    }
}
