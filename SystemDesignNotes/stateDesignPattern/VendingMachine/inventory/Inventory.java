package inventory ;

import item.* ; 

public class Inventory {
    ItemSelve selves[] ; 
    int selveMax ;

    public Inventory(int inventCount, int selveMax){
        selves = new ItemSelve[inventCount] ;
        this.selveMax = selveMax ; 
        initializeEmptyInventory() ; 
    }

    void initializeEmptyInventory(){
        int startCode = 100 ; 
        for(int i = 0 ; i < selves.length ; i++){
            selves[i] = new ItemSelve(startCode, selveMax) ;
            startCode++ ; 
        }

        return ;
    }

    public void addItem(Item item, int selveCode, int qty) throws Exception {
        for(ItemSelve selve : selves){
            if(selve.getCode() == selveCode){
                if(selve.isSoldOut() ){
                    selve.setItem(item) ;
                    selve.addQuantity(qty) ;
                    return ; 
                }else{
                    throw new Exception("Unable to add ITEM to the selves : " + selveCode) ;
                }
            }
        }
        throw new Exception("SELVE doesn't exist"); 
    }

    public Item getItem(int selveCode) throws Exception {
        for(ItemSelve selve : selves){
            if(selve.getCode() == selveCode){
                if(!selve.isSoldOut() ){
                    return selve.getItem() ; 
                }else{
                    throw new Exception("ITEM from the selves " + selveCode + " is Sold out :")   ;
                }
            }
        }
        throw new Exception("SELVE doesn't exist"); 
    }

    public Item buyItem(int selveCode) throws Exception {
        for(ItemSelve selve : selves){
            if(selve.getCode() == selveCode){
                if(!selve.isSoldOut() ){
                    return selve.buyItem() ; 
                }else{
                    throw new Exception("ITEM from the selves " + selveCode + " is Sold out :")   ;
                }
            }
        }
        throw new Exception("SELVE doesn't exist"); 
    }

}