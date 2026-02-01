package warehouse;
import product.* ; 
import java.util.*;

public class Inventory {
    ArrayList<ProductStock> productStocks ;
    public Inventory(){
        this.productStocks = new ArrayList<>() ; 
    }
    public void addProductStock( ProductStock ps ){
        this.productStocks.add(ps) ;
    }
    public void removeProductStock( ProductStock ps ){
        this.productStocks.remove(ps) ;
    }
    public ProductStock getProductStockByName( String name ){
        for( ProductStock ps : this.productStocks ){
            if( ps.getName().equals(name) ){
                return ps ;
            }
        }
        return null ;
    }
    public ProductStock getProductStockById( int id ){
        for( ProductStock ps : this.productStocks ){
            if( ps.getId() == id ){
                return ps ;
            }
        }
        return null ;
    }

    public void updateAfterOrder( Map<Integer, Integer> productStockIdToCountMap ){
        for( Map.Entry<Integer, Integer> entry : productStockIdToCountMap.entrySet() ){
            int stockId = entry.getKey() ;
            int count = entry.getValue() ;
            ProductStock ps = this.getProductStockById(stockId) ;
            if( ps != null ){
                for( int i = 0 ; i < count ; i++ ){
                    if( ps.getStockCount() > 0 ){
                        ps.removeProduct() ;
                    }
                }
            }
        }
    }

    public ArrayList<ProductStock> getAllProductStocks(){
        return this.productStocks ;
    }

    public void display(){
        for( ProductStock ps : this.productStocks ){
            System.out.println("ProductStock ID: " + ps.getId() + ", Name: " + ps.getName() + ", Price: " + ps.getPrice() + ", Stock Count: " + ps.getStockCount() ) ;
        }
    }
}
