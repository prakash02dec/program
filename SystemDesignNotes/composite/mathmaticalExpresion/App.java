public class App {
    public static void main(){
        // (a+ b)*(c-d)
        // (7+10)*(14- 4) = 170
        MathmaticalExpression exp = new Expression(
                                    new Expression( new Number(7), Operation.ADD, new Number(10)) , 
                                    Operation.MULTIPLY , 
                                    new Expression(new Number(14), Operation.SUBTRACT , new Number(4))
                                    ) ;
        
        try{
            System.out.println(exp.evaluate())   ;
        }catch(Exception e){
            System.out.println(e) ;
        }
    }
}