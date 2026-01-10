package mediator ; 
import bidders.* ; 

public interface Mediator {
    public void placeBid(int amount, Bidder bidder) ; 
    public void registorBidders(Bidder bidder);
    public void closeBidding() ;
}