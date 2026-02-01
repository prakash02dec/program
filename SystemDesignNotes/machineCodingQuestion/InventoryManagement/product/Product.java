package product;

public class Product {
    static int idCounter = 10000 ;
    int id ; 
    String name ;
    public Product(String name ){
        this.name = name ;
        this.id = idCounter++ ;
    }
}
