package Toppings ; 

import Pizza.Pizza ; 

public class PaneerTopping extends ToppingDecorator {
    public PaneerTopping(Pizza pizza){
        super(pizza) ;
    }
    @Override 
    public String getDescription(){
        return pizza.getDescription() + "with paneer topping" ;
    }

    @Override
    public int getCost(){
        return pizza.getCost() + 30 ; 
    }
}