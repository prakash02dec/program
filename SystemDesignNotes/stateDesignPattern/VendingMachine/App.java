import item.* ; 
import vendingMachine.* ; 

public class App {
    public static void main() throws Exception {
        // Inventory inv = new Inventory(10, 10) ;
        // Item coke = new Item( ItemType.COKE, 40 ) ;
        // try {
        // inv.addItem(coke, 101, 4) ;
        // Item item = inv.getItem(101) ;
        // Item item1 = inv.getItem(101) ;
        // Item item2 = inv.getItem(101) ;
        // Item item3 = inv.getItem(101) ;
        // // Item item4 = inv.getItem(101) ;
        // System.out.println(item.getType().name()) ;
        // }catch(Exception e){
        //     System.out.println(e) ;
        // }
        try {
            VendingMachine machine = new VendingMachine(10, 10) ;
            Item coke = new Item( ItemType.COKE, 30 ) ;
            machine.getState().updateInventory(machine, coke, 101, 3);
            machine.getState().clickOnInsertCoinButton(machine) ;
            machine.getState().insertCoin(machine, Coin.TEN) ;
            // machine.getState().insertCoin(machine, Coin.TWENTY) ;
            machine.getState().clickOnProductSelectionButton(machine) ;
            machine.getState().selectProduct(machine, 101) ;
            
        }catch(Exception e){
            System.out.println( e );
        }

        return ; 
    }
}