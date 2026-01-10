import bidders.* ; 
import mediator.* ; 

public class App {
    public static void main(String args[]){
        Mediator auction = new AuctionHouse() ;
        Bidder bid2 = new Participants(auction , "jack") ; 
        Bidder bid1 = new Participants(auction, "oggy") ; 
        Bidder bid3 = new Participants(auction, "shinchan") ;
        bid1.placeBid(100) ;
        bid2.placeBid(10) ;
        bid3.placeBid(200) ;
        bid2.placeBid(250) ;
        auction.closeBidding() ; 
    }
}