package shapes ; 

public class Square implements Shape {
    public int side ;
    public Square(int s){
        side = s ; 
    }

    @Override
    public void area(){
        System.out.println("Area of the Square is : " +  side*side) ;
    }

    @Override
    public void draw(){
        System.out.printf("\nDrawing a rectangle with sides length : %d ", side) ; 
    }
}