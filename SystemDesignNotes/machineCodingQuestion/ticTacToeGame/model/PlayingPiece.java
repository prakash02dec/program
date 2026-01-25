package model;

public abstract class PlayingPiece {
    public PieceType pieceType;
    public PlayingPiece(PieceType pieceType){
        this.pieceType = pieceType;
    }
    public abstract PieceType getPieceType();
}
