package cart;

import java.util.*;
import product.*; 

public class Cart {
    int userId ; 
    Map<Integer, Integer> ProductStockIdToCountMap ;
    public Cart( int userId ){
        this.userId = userId ;
        this.ProductStockIdToCountMap = new HashMap<>() ;
    }

    public void addProductStock( ProductStock productStock, int count ){
        int productStockId = productStock.getId() ;
        System.out.println("Adding ProductStockId: " + productStockId + ", Count: " + count + " to cart.") ;
        int curr = this.ProductStockIdToCountMap.getOrDefault(productStockId, 0) ; 
        int newCount = Math.min(count+curr, productStock.getStockCount()) ;
        this.ProductStockIdToCountMap.put( productStockId,  newCount ) ;
    }

    public Map<Integer, Integer> getAllProductStocks(){
        return this.ProductStockIdToCountMap ;
    }

    public void viewCart(){
        for( Map.Entry<Integer, Integer> entry : this.ProductStockIdToCountMap.entrySet() ){
            System.out.println("ProductStockId: " + entry.getKey() + ", Count: " + entry.getValue() ) ;
        }
    }

    public void clearCart(){
        this.ProductStockIdToCountMap.clear() ;
    }

}
