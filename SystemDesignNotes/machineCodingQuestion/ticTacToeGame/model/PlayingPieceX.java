package model;

public class PlayingPieceX extends PlayingPiece {
    public PlayingPieceX(){
        super(PieceType.X);
    }
    @Override
    public PieceType getPieceType(){
        return pieceType;
    }
}
