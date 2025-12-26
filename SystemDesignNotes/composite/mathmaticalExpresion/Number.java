public class Number implements MathmaticalExpression {
    int value ; 

    public Number(int value){
        this.value = value ; 
    }

    @Override 
    public int evaluate() throws Exception{
        return value ; 
    }
}