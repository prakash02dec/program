import shapes.* ;
import shapeFactory.* ;
import ShapeFactoryMethod.ShapeFactoryMethodProvider ;

public class App{
    public static void main() { 
        Shape circle = ShapeFactoryDemo.createShape(ShapeType.CIRCLE, new int[]{10}) ;
        Shape rectangle = ShapeFactoryDemo.createShape(ShapeType.RECTANGLE, new int[]{10, 15}) ;
        circle.draw() ; 
        rectangle.draw();
        Shape Circle2 = ShapeFactoryMethodProvider.createShape(ShapeType.CIRCLE, new int[]{10}) ;
        Circle2.draw() ; 
    }
}
