import game.* ; 
import model.GameStatus ; 
public class App {

    public static void main(String args[]){
        Game game = new Game(3) ;
        GameStatus status = game.start() ; 
        switch(status){
            case GameStatus.DRAW :
                    System.out.println("Game has been DRAW") ;      
                    break ; 
            case GameStatus.WIN :
                    System.out.println("[Player]: " + game.winner.getName() + " has won the game") ;
                    break ; 
            default :
                System.out.println("INVALID STATUS OF THE GAME") ;
        }
        return ; 
    }
}