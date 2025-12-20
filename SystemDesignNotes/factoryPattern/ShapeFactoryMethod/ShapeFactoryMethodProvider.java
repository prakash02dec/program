package ShapeFactoryMethod  ;

import shapes.* ; 

public class ShapeFactoryMethodProvider { 
    public static Shape  createShape(ShapeType type, int arr[]){
    if(type == null) return null ; 
    switch(type){
        case RECTANGLE :
            RectangleFactory rectangleCreater = new RectangleFactory() ; 
            return rectangleCreater.getShapeInstance(arr[0], arr[1]) ;
        case CIRCLE :
            CircleFactory circleCreator = new CircleFactory() ; 
            return circleCreator.getShapeInstance(arr[0]) ;
        case SQUARE :
            SquareFactory squareCreator = new SquareFactory() ; 
            return squareCreator.getShapeInstance(arr[0]) ;
        default :
            throw new IllegalArgumentException("State is not define") ;
    }

} 
}