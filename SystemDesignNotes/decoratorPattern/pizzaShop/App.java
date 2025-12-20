import Pizza.* ; 
import Toppings.* ; 

public class App {
    public static void main(String[] ags){
        Pizza cheesePizza = new ExtraCheese(new PlainPizza()) ;
        System.out.println(cheesePizza.getDescription() + " at cost : " + cheesePizza.getCost() ) ;

        Pizza FarmhousePizzaWithCheeseAndPaneer = new PaneerTopping( new ExtraCheese(new FarmhousePizza()) ) ;
        System.out.println(FarmhousePizzaWithCheeseAndPaneer.getDescription() + " at cost : " + FarmhousePizzaWithCheeseAndPaneer.getCost() ) ;

        Pizza peppyPaneer = new PeppyPaneerPizza() ;
        System.out.println(peppyPaneer.getDescription() + " at cost : " + peppyPaneer.getCost() ) ;

        return ; 
    }
}