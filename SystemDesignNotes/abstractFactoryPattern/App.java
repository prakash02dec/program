import carProduction.* ;
import factoryProvider.* ;
// import 
public class App {
    public static void main(String args[] ){
        CarProduction  luxury = FactoryProvider.getProduction("farari", FactoryType.LUXURY) ;
        luxury.startProduction() ;
        System.out.println() ; 
        CarProduction economy = FactoryProvider.getProduction("Tata", FactoryType.ECONOMY) ;
        economy.startProduction() ; 

        return ; 
    }
}