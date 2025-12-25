package vendingMachine.state;
import java.util.* ; 
import vendingMachine.*;

public class RefundState extends VendingMachineState{
    public RefundState(VendingMachine obj) throws Exception{
        System.out.println("Machine is Processing your refund.") ;
        refundFullMoney(obj) ;
    }

    @Override
    public ArrayList<Coin> refundFullMoney(VendingMachine obj) throws Exception {
        ArrayList<Coin> refunds = new ArrayList<Coin> (obj.getCoins());
        obj.getCoins().clear() ; 
        obj.setState(new IdleState()) ;
        System.out.println("Please collect money from the coin tray :" + refunds) ;
        return refunds ; 
    }
}
