package shapes ; 

public class Circle implements Shape {
    public int radius ; 
    public Circle(int r){
        radius = r ; 
    }

    @Override
    public void area(){
        System.out.println("Area of the circle is : " +  2*3.14*radius) ;
    }

    @Override
    public void draw(){
        System.out.println("\nDrawing a circle with radius " + radius) ; 
    }

}