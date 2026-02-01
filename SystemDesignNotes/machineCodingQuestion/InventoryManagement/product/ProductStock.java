package product;
import java.util.* ; 
public class ProductStock {
    double price ; 
    ArrayList<Product> products ;
    int stockId ; 
    String name ; 

    static int stockIdCounter = 5000 ;


    public ProductStock( String name , double price  ){
        this.name = name ; 
        this.price = price ; 
        this.stockId = stockIdCounter++ ;
        this.products = new ArrayList<>() ; 
    }
    public void addProduct( Product p ){
        this.products.add(p) ; 
    }
    public void removeProduct(){
        if( !products.isEmpty() ){
            products.remove(0) ;
        }
    }
    public double getPrice(){
        return this.price ;
    }
    public int getStockCount(){
        return this.products.size() ;
    }
    public String getName(){
        return this.name ;
    }
    public int getId(){
        return this.stockId ;
    }
}
