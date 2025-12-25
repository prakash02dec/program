package vendingMachine.state ; 

import item.* ;
import vendingMachine.* ; 

public class IdleState extends VendingMachineState {
    
    public IdleState(){
        System.out.println("Machine in its Idle State") ;
    }

    @Override
    public void updateInventory(VendingMachine obj, Item item, int selveCode, int qty) throws Exception {
        obj.getInventory().addItem(item, selveCode, qty) ;
    }

    @Override
    public void clickOnInsertCoinButton(VendingMachine obj) throws Exception {
        obj.setState( new HasMoneyState() ) ;
    }
}