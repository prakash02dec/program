package order.invoice;
import java.util.* ;

import warehouse.*;
import product.*;
public class Invoice {
    private static int invoiceIdCounter = 20000 ;
    public  int invoiceId ;
    public  int userId ; 
    public double totalAmount ;
    public double tax ;
    public double discount ;
    public double finalAmount ;

    public Invoice(int userId, Map<Integer, Integer> productStockIdToCountMap, Warehouse warehouse ){
        this.invoiceId = invoiceIdCounter++ ;
        this.userId = userId ;
        this.totalAmount = 0 ;
        this.tax = 0 ;
        this.discount = 0 ;
        this.finalAmount = 0 ;

        for( Map.Entry<Integer, Integer> entry : productStockIdToCountMap.entrySet() ){
            ProductStock ps = warehouse.getInventory().getProductStockById( entry.getKey() ) ;
            if( ps != null ){
                this.totalAmount += ps.getPrice() * entry.getValue() ;
            }
        }
        this.tax = this.totalAmount * 0.18 ; // Assuming 18% tax rate
        this.discount = 50 ; // Assuming a fixed discount of 10
        this.finalAmount = Math.max(this.totalAmount + this.tax - this.discount, 0);
    }

    public static int getInvoiceIdCounter() {
        return invoiceIdCounter;
    }

    public int getInvoiceId() {
        return invoiceId;
    }

    public int getUserId() {
        return userId;
    }

    public double getTotalAmount() {
        return totalAmount;
    }

    public double getTax() {
        return tax;
    }

    public double getDiscount() {
        return discount;
    }

    public double getFinalAmount() {
        return finalAmount;
    }
    
}
