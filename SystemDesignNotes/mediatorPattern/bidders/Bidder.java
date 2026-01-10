package bidders ; 

public interface Bidder {
    public void placeBid(int bid) ; 
    public void recieveNotification(int bidAmount) ; 
    public String getName() ;
}