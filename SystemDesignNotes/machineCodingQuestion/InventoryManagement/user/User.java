package user;

import java.util.*;

import cart.Cart;
import order.Order;
import utils.Address;

public class User {
    static int userCounter = 1 ; 

    int userId ;
    String name ;
    String email ;
    String phoneNumber ;
    Address address ;
    ArrayList<Order> orders ;
    Cart cart ; 

    public User(String name, String email, String phoneNumber, Address address ){
        this.userId = userCounter++ ;
        this.name = name ;
        this.email = email ;
        this.phoneNumber = phoneNumber ;
        this.address = address ;
        cart = new Cart(this.userId) ;
        this.orders = new ArrayList<>() ;
    }

    public int getId() {
        return userId;
    }

    public String getName() {
        return name;
    }

    public String getEmail() {
        return email;
    }

    public String getPhoneNumber() {
        return phoneNumber;
    }

    public Address getAddress() {
        return address;
    }

    public Cart getCart() {
        return cart;
    }

    public void getAllOrders(){
        for( Order o : this.orders ){
            System.out.println(o);
        }
    }

    public void viewCart(){
        System.out.println("\nViewing Cart contents for user: " + this.name );
        this.cart.viewCart();
    }

    public void addOrder( Order order ){
        this.orders.add(order) ;
    } 

    

}
