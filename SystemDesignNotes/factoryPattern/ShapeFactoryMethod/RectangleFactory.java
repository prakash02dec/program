package ShapeFactoryMethod;

import shapes.Rectangle;
import shapes.Shape;

public class RectangleFactory implements ShapeFactoryMethod {
    @Override
    public Shape getShapeInstance(int ...args){
        int a = args[0] ;
        int b = args[1] ;
        return new Rectangle(a, b) ; 
    }
}

