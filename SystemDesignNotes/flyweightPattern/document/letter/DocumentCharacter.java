package  letter ; 


public class DocumentCharacter implements Letter {
    int size ;
    String font ; 
    char ch ; 

    public DocumentCharacter(int size, String font, char ch) {
        this.size = size ;
        this.font = font ; 
        this.ch = ch ; 
    }

    @Override 
    public void display(int x, int y) {
        System.out.println("letter : " + ch + " font : " + font + " size : " + size) ;
    }
    
}