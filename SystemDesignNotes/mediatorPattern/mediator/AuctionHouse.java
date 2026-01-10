package mediator ; 
import bidders.* ; 
import java.util.* ; 

public class AuctionHouse implements Mediator{
    ArrayList<Bidder> bidders ; 
    Bidder currHighestBidder ; 
    int currhighestBid ; 
    String item ; 

    public AuctionHouse(){
        currhighestBid = 0 ; 
        currHighestBidder = null ;
        bidders = new ArrayList<>() ; 
    }

    @Override
    public void placeBid(int amount, Bidder bidder) {
        if(amount <= currhighestBid){
            System.out.println(bidder.getName() + " => Please raise your bid as the curr highest bid is : " + currhighestBid) ;
            return ; 
        }
        currHighestBidder = bidder ; 
        currhighestBid = amount ; 
        System.out.println(bidder.getName()+" Bidder has successfully place bid of amount " + amount );
        for(Bidder indi : bidders){
            if(indi.getName().equals(bidder.getName())) continue ; 
            indi.recieveNotification(amount) ;
        }
    }

    @Override
    public void registorBidders(Bidder bidder) {
        bidders.add(bidder) ;
    }

    @Override
    public void closeBidding(){
        System.out.println("Closing the Auction for the item ;" + item ) ;
        System.out.println("Auction winner is " + currHighestBidder.getName()  + " who place bid amount of " + currhighestBid ) ;
    }
}