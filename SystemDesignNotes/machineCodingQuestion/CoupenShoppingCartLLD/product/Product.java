package product;

public  abstract class Product {
    public ProductType productType;
    public String name;
    public double price;

    public Product() {} 

    public Product(ProductType productType, String name, double price) {
        this.productType = productType;
        this.name = name;
        this.price = price;
    }

    public ProductType getProductType() {
        return productType;
    }
    public String getName() {
        return name;
    }

    public abstract double getPrice(); 

}
