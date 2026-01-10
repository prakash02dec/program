package bidders ; 
import mediator.* ; 
public class Participants implements Bidder {
    String name ; 
    Mediator mediator ; 

    public Participants(Mediator mediator, String name){
        this.name = name ; 
        this.mediator = mediator ; 
        mediator.registorBidders(this) ;
    }

    @Override
    public void placeBid(int bid){
        mediator.placeBid(bid, this) ;
    }

    @Override
    public void recieveNotification(int bidAmount){
        System.out.println("[+] Bidder "+ name +" recieve notificaton of New Bid has been placed for amount " + bidAmount) ;
    }

    @Override
    public String getName(){
        return name ; 
    }
}