package carInterior ; 

public class EconomyCarInterior implements CarInterior {
    @Override 
    public void addInteriorComponent(){
        System.out.println("Adding Interior Component with basic material and quality") ;
    }
}