package game;

import model.* ; 
import java.util.* ; 

public class Game { 
   public Board board ; 
   public Deque<Player> players ; 
   public Player winner ; 
   public GameStatus status ; 

   public Game(int size){
        board = new Board(size) ;
        players = new ArrayDeque<>() ; 
        init() ; 
   }

   public void init(){
        PlayingPiece O = new PlayingPieceO() ; 
        PlayingPiece X = new PlayingPieceX() ; 
        Player player1 = new Player("Prakash", X) ;
        Player player2 = new Player("Rakash", O) ; 
        players.add(player1) ;
        players.add(player2) ;
   }

   public GameStatus start(){
        while(true){
            Player currPlayer = players.removeFirst() ; 
            board.display();
            ArrayList<ArrayList<Integer>> freeCells = board.getFreeCells() ; 
            if(freeCells.isEmpty()){
                break ; 
            }

            System.out.println("[Player] : " + currPlayer.getName() +" - Please enter row and column as r,c ") ;
            Scanner scanner = new Scanner(System.in) ;
            String coords[] = scanner.nextLine().split(",") ; 
            int row = Integer.valueOf(coords[0]) ;
            int col = Integer.valueOf(coords[1]) ;
            
            boolean isValid = board.addPlayingPiece(row, col, currPlayer.playingPiece) ; 
            if(!isValid){
                System.out.println("[Player] : " + currPlayer.getName() +" - Please enter valid one which is empty ") ;
                players.addFirst(currPlayer) ;
                continue ; 
            }
            players.addLast(currPlayer);
            
            boolean isWinner =  checkWinner(row, col, currPlayer.playingPiece) ;
            if(isWinner){
                board.display() ; 
                winner = currPlayer ; 
                return GameStatus.WIN ; 
            }

        }
        status = GameStatus.DRAW ;
        return status ; 
   }

   public boolean checkWinner(int row, int col, PlayingPiece piece){
        boolean rowMatch = true ;
        boolean colMatch = true ;
        boolean diaMatch = true ;
        boolean antiDiaMatch = true ;

        for(int i = 0 ; i < board.size ; i++) {
            if(board.board[row][i] == null || board.board[row][i] != piece){
                rowMatch = false ; 
                break ;
            }
        }

        for(int i = 0 ; i < board.size ; i++) {
            if(board.board[i][col] == null || board.board[i][col] != piece){
                colMatch = false ; 
                break ;
            }
        }

        for(int i = 0 ; i < board.size ; i++) {
            if(board.board[i][i] == null || board.board[i][i] != piece){
                diaMatch = false ; 
                break ;
            }
        }

        for(int i = 0 ; i < board.size ; i++) {
            if(board.board[i][board.size -1 - i] == null || board.board[i][board.size -1 - i] != piece){
                antiDiaMatch = false ; 
                break ;
            }
        }

        return rowMatch || colMatch || diaMatch || antiDiaMatch ; 
   }

   

}
