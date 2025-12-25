package vendingMachine ; 
import java.util.* ; 
import inventory.* ;
import vendingMachine.state.* ; 

public class VendingMachine {
    VendingMachineState state ; 
    ArrayList<Coin> coins ; 
    Inventory inventory ; 

    public VendingMachine(int inventCount, int selveMaxSize){
        state = new IdleState() ; 
        coins = new ArrayList<Coin> () ; 
        inventory = new Inventory( inventCount, selveMaxSize) ; 
    }

    public void setState(VendingMachineState state){
        this.state = state ; 
    }

    public VendingMachineState getState(){
        return state ;  
    }

    public Inventory getInventory(){
        return this.inventory ; 
    }

    public ArrayList<Coin> getCoins(){
        return coins ; 
    }

}
