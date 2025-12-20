package shapeFactory  ;
import shapes.* ;

public interface ShapeFactoryDemo {
    public static Shape  createShape(ShapeType type, int arr[]){
        if(type == null) return null ; 
        switch(type){
            case RECTANGLE :
                return new Rectangle(arr[0], arr[1]) ;
            case CIRCLE :
                return new Circle(arr[0]) ;
            case SQUARE :
                return new Square(arr[0]) ;
            default :
                throw new IllegalArgumentException("State is not define") ;
        }

    } 
}