package Toppings ;
import Pizza.Pizza ; 

public abstract class ToppingDecorator implements Pizza {
    protected final Pizza pizza ; 
    public ToppingDecorator(Pizza pizza){
        this.pizza = pizza ; 
    }
}