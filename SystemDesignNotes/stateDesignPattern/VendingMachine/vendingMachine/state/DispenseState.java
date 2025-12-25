package vendingMachine.state ; 
import item.* ;
import vendingMachine.* ; 

public class DispenseState extends VendingMachineState {

    public DispenseState(VendingMachine obj, int code) throws Exception {
        System.out.println("Machine in its Dispensing Product State") ;
        dispenseProduct(obj, code) ;
    }

    @Override
    public Item dispenseProduct(VendingMachine obj, int code) throws Exception{
        Item  item = obj.getInventory().buyItem(code) ;
        System.out.println("Please collect "+ item.getType() + " from the dispense tray") ;
        obj.setState(new IdleState()) ;
        return item ;
    }

    
}