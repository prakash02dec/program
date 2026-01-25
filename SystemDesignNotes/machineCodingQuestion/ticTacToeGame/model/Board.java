package model;

import java.util.* ; 

public class Board {
    public int size ;
    public PlayingPiece board[][] ;

    public Board(int size){
        this.size = size ; 
        board = new PlayingPiece[size][size] ;
         
    }

    public boolean addPlayingPiece(int r, int c, PlayingPiece playingPiece){
        if(board[r][c] != null) return false ; 
        board[r][c] = playingPiece ; 
        return true ; 
    }
    
    public ArrayList<ArrayList<Integer>> getFreeCells() {
        ArrayList<ArrayList<Integer>> freeCells = new ArrayList<>();
        for(int i = 0 ; i < size ; i++){
            for(int j = 0 ; j < size ; j++){
                if(board[i][j] == null){
                    freeCells.add(new ArrayList<>(Arrays.asList(i, j))) ;
                }
            }
        }
        return freeCells;
    }

    public void display() {
        for(int i = 0 ; i < size ; i++){

            for(int j = 0 ; j < size ; j++){
                if(board[i][j] == null){
                    System.out.print("   ") ;
                }else{
                    System.out.print(" " + board[i][j].pieceType.name() + " ") ;
                }

                System.out.print(" | ") ;
            }
            
            System.out.println() ; 
        }
    }

}


