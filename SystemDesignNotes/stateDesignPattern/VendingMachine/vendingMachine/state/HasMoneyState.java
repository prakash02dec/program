package vendingMachine.state ; 

import vendingMachine.* ; 

public class HasMoneyState extends VendingMachineState {

    public HasMoneyState(){
        System.out.println("Machine in its Collecting Money State") ;
    }

    @Override
    public void insertCoin(VendingMachine obj, Coin coin) throws Exception {
        System.out.println("Recieved " + coin.value + " rupees coin") ;
        obj.getCoins().add(coin) ;
    }

    @Override
    public void clickOnProductSelectionButton(VendingMachine obj) throws Exception{
        obj.setState(new SelectionState()) ;
    }

    @Override
    public void cancel(VendingMachine obj) throws Exception {
        obj.setState(new RefundState(obj)) ;
    }
}