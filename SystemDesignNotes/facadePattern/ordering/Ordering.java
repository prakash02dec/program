package ordering ; 
import notification.* ; 
import order.* ; 
import payment.* ; 
import shipping.* ; 

public class Ordering {
    NotificationService notification ; 
    OrderService order ; 
    PaymentService payment ; 
    ShippingService shipping ; 
    public Ordering(){
        notification = new NotificationService() ; 
        order = new OrderService() ; 
        payment = new PaymentService() ; 
        shipping = new ShippingService() ;
    }
    public void placeOrder(){
        order.createOrder() ; 
        payment.pay() ; 
        shipping.startShipping() ; 
        notification.sendNotification() ; 
    }
}