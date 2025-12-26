public class Expression implements MathmaticalExpression {
    MathmaticalExpression left ;
    Operation ops ; 
    MathmaticalExpression right ; 

    public Expression(MathmaticalExpression left, Operation ops, MathmaticalExpression right){
        this.left = left ; 
        this.ops = ops ; 
        this.right = right ; 
    }

    @Override
    public int evaluate() throws Exception{
        switch(ops){
            case ADD :
                return left.evaluate() + right.evaluate() ; 
            case SUBTRACT :
                return left.evaluate() - right.evaluate() ; 
            case MULTIPLY :
                return left.evaluate() * right.evaluate() ; 
            case DIVISION :
                return left.evaluate() / right.evaluate() ; 
            default : 
                throw new Exception("Invalid Operation, "+ ops + " operation is not supported") ;
        }
    }
}