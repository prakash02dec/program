package inventory ; 
import java.util.* ; 
import item.* ; 

public class ItemSelve { 
    Item item  ; 
    int quantity ; 
    int maxQuantity ; 
    boolean soldOut ; 
    int code ; 

    public ItemSelve(int code, int maxQuantity){
        this.code = code ; 
        this.maxQuantity = maxQuantity ; 
        this.soldOut = true ; 
    }

    public int getCode() {
        return this.code ; 
    }

    public int getMaxQuantity() {
        return this.maxQuantity ; 
    }


    public void setItem(Item item){
        this.item = item ;
    }

    public int getQuantity(){
        return this.quantity ; 
    }

    public int addQuantity(int qty){
        int extra = quantity + qty - maxQuantity ;
        quantity = Math.min(quantity + qty, maxQuantity);

        if(quantity > 0) {
            soldOut = false ; 
        }
        
        return (extra > 0 ? extra : 0) ;
    }

    public Item getItem() throws Exception {
        if(!soldOut){
            return this.item ; 
        }
        throw new Exception( item.getType().toString() + " is out STOCK" ) ; 
    }

    public Item buyItem() throws Exception {
        if(!soldOut){
            this.quantity-- ; 
            if(quantity == 0) soldOut = true ; 
            return this.item ; 
        }
        throw new Exception( item.getType().toString() + " is out STOCK" ) ; 
    } 
    
    public boolean isSoldOut(){
        return soldOut ; 
    }
    
}