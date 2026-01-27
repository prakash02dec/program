package vendingMachine.state ; 

import item.* ;
import java.util.* ;
import vendingMachine.* ; 

public abstract class VendingMachineState{
    public void updateInventory(VendingMachine obj, Item item, int selveCode, int qty) throws Exception {} 
    public void clickOnInsertCoinButton(VendingMachine obj) throws Exception {}  
    public void insertCoin(VendingMachine obj, Coin coin) throws Exception {} 
    public void clickOnProductSelectionButton(VendingMachine obj) throws Exception {} 
    public void selectProduct(VendingMachine obj, int code) throws Exception {} 
    public Item dispenseProduct(VendingMachine obj, int code) throws Exception { return null ; }
    public ArrayList<Coin> refundFullMoney(VendingMachine obj) throws Exception { return null ; }
    public void cancel(VendingMachine obj) throws Exception {}
}