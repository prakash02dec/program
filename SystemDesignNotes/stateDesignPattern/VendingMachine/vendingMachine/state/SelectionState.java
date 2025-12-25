package vendingMachine.state ; 

import item.* ;
import vendingMachine.* ; 

public class SelectionState extends VendingMachineState {

    public SelectionState(){
        System.out.println("Machine in its Selecting Product State") ;
    }
    @Override
    public void cancel(VendingMachine obj) throws Exception {
        obj.setState(new RefundState(obj)) ;
    }

    @Override
    public void selectProduct(VendingMachine obj, int code) throws Exception {
        Item item = obj.getInventory().getItem(code) ;
        int cost  = item.getPrice() ; 

        int deposit = 0 ; 
        for(Coin coin : obj.getCoins() ){
            deposit += coin.value ; 
        }

        if(deposit < cost){
            System.out.println("Refunding full money as paid by you is : " +deposit + " and actual cost of item is : " + item.getPrice() ) ;
            obj.setState(new RefundState(obj));
        }else{
            int change = deposit - cost ; 
            System.out.println("Your change is : " + change) ;
            obj.setState(new DispenseState(obj, code) ) ;
        }

    }
}