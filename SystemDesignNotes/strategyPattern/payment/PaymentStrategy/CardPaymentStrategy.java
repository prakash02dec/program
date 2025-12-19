package PaymentStrategy ;

public class CardPaymentStrategy implements PaymentStrategy {
    private String card ; 
    
    public CardPaymentStrategy(String card){
        this.card = card ; 
    }
    
    @Override
    public void pay(double amount){
        System.out.println("Paying " + amount + " with the card [last 4 digit] : " + card.substring(card.length() - 4) ) ;
    }
}