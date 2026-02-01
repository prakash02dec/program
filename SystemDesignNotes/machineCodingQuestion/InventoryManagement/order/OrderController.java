package order;

import java.util.* ;
import user.* ; 
import cart.* ;
import payment.Payment;
import warehouse.* ;
public class OrderController {
    static ArrayList<Order> orders = new ArrayList<>() ;
    
    public OrderController(){
       
    }
    public Order processCheckout(User u, Warehouse warehouse ){
        Cart cart = u.getCart() ;
        Map<Integer, Integer> productStockIdToCountMap = cart.getAllProductStocks() ;
        // select warehouse logic can be added here
        Order order = new Order( u.getId(), productStockIdToCountMap, warehouse ) ;
        Payment payment = new Payment("UPI", order.finalAmount ) ;
        order.setShippingAddress(u.getAddress());
        warehouse.updateInventoryAfterOrder( productStockIdToCountMap ) ;
        order.setPayment(payment) ;
        order.setOrderStatus( OrderStatus.CONFIRMED ) ;
        u.addOrder(order) ;
        orders.add(order) ;
        return order ;
    }
}
