package order;

import java.util.HashMap;
import java.util.Map;

import order.invoice.Invoice;
import payment.Payment;
import utils.Address;
import warehouse.Warehouse;

public class Order {
    int userId ;
    Invoice invoice ;
    Map<Integer, Integer> productStockIdToCountMap ;
    Address shippingAddress ;
    OrderStatus orderStatus ;
    double finalAmount ;
    Warehouse warehouse ;
    Payment payment ;

    public Order( int userId, Map<Integer, Integer> productStockIdToCountMap, Warehouse warehouse ){
        this.userId = userId ;
        this.warehouse = warehouse ;
        this.invoice = new Invoice(userId, productStockIdToCountMap, warehouse) ;
        this.finalAmount = this.invoice.getFinalAmount() ;
        this.productStockIdToCountMap = new HashMap<Integer,Integer>(productStockIdToCountMap) ;
    }

    public void setPayment(Payment payment){
        this.payment = payment ;
    }
    public void setShippingAddress( Address address ){
        this.shippingAddress = address ;
    }
    public void setOrderStatus( OrderStatus status ){
        this.orderStatus = status ;
    }

    @Override
    public String toString() {
        return "Order{" +
                "userId=" + userId +
                ", invoiceId=" + invoice.getInvoiceId() +
                ", finalAmount=" + finalAmount +
                ", orderStatus=" + orderStatus +
                '}';
    }
}
