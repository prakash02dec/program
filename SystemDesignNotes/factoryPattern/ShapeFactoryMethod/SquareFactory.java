package ShapeFactoryMethod;

import shapes.Shape;
import shapes.Square;

public class SquareFactory implements ShapeFactoryMethod {
    @Override
    public Shape getShapeInstance(int ...args){
        int x = args[0] ;
        return new Square(x) ; 
    }
}
