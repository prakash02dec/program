package ShapeFactoryMethod  ;
import shapes.* ; 

public class CircleFactory implements ShapeFactoryMethod {
    @Override
    public Shape getShapeInstance(int ...args){
        int r = args[0] ;
        return new Circle(r) ; 
    }
}

