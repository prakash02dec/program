package vendingMachine ; 

public enum Coin{
    ONE(1),
    TWO(2),
    FIVE(5),
    TEN(10),
    TWENTY(20);

    public int value ; 

    Coin(int val){
        this.value = val ; 
    }
    
}