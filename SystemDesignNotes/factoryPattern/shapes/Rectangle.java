package shapes ; 

public class Rectangle implements Shape {
    public int length ;
    public int breadth ;  
    public Rectangle(int l , int b){
        length = l ; 
        breadth = b ; 
    }

    @Override
    public void area(){
        System.out.println("Area of the Rectangle is : " +  length*breadth) ;
    }

    @Override
    public void draw(){
        System.out.printf("\nDrawing a rectangle with sides length : %d and %d\n", length, breadth) ; 
    }
}