package Toppings ; 

import Pizza.Pizza ; 

public class ExtraCheese extends ToppingDecorator {
    public ExtraCheese(Pizza pizza){
        super(pizza) ;
    }

    @Override 
    public String getDescription(){
        return pizza.getDescription() + " with Extra cheese" ;
    }

    @Override
    public int getCost(){
        return pizza.getCost() + 40 ; 
    }
}