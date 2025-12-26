import adapter.* ; 
import square.* ; 
import round.* ; 

public class App {
    public static void main(String args[]){
        RoundPeg rp1 = new RoundPeg(10) ;
        RoundPeg rp2 = new RoundPeg(13) ;
        RoundHole hole = new RoundHole(13) ;
        
        if(hole.isfit(rp1)){
            System.out.println("Rp1 is fit to the hole") ;
        }
        if(hole.isfit(rp2)){
            System.out.println("Rp2 is fit to the hole") ;
        }

        SquarePeg sq = new SquarePeg(10) ;
        SquarePegAdapter sqa = new SquarePegAdapter(sq) ;
        if(hole.isfit(sqa)){
            System.out.println("sqa is fit to the hole") ;
        }
        
    }
}