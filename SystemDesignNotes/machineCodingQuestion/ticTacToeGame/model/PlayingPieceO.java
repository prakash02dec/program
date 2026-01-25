package model;

public class PlayingPieceO extends PlayingPiece {
    public PlayingPieceO(){
        super(PieceType.O) ;
    }
    @Override
    public PieceType getPieceType(){
        return pieceType ; 
    }
}
