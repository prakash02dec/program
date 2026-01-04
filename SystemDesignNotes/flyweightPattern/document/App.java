import letter.* ; 

public  class App {
    public static  void main(String args[]){
        LetterFactory factory = new LetterFactory() ; 
        DocumentCharacter P = factory.createLetter('P', 2, "Arial") ;
        DocumentCharacter r = factory.createLetter('r', 2, "Italic") ;
        DocumentCharacter a = factory.createLetter('a', 2, "Arial") ;
        DocumentCharacter k = factory.createLetter('k', 2, "Roman") ;
        DocumentCharacter a2 = factory.createLetter('a', 2, "Arial")  ;
        DocumentCharacter s = factory.createLetter('s', 2, "Robot") ;
        DocumentCharacter h = factory.createLetter('h', 2, "Arial") ;
        DocumentCharacter A = factory.createLetter('A', 2, "Arial") ;
        DocumentCharacter g = factory.createLetter('g', 2, "Arial") ;
        DocumentCharacter a3 = factory.createLetter('a', 2, "Arial") ;
        DocumentCharacter r2 = factory.createLetter('r', 2, "Arial") ;
        DocumentCharacter w = factory.createLetter('w', 2, "Arial") ;
        DocumentCharacter a4 = factory.createLetter('a', 2, "Arial") ;
        DocumentCharacter l = factory.createLetter('l', 2, "Arial") ;
        P.display(1, 0);
        r.display(1, 1);
        a.display(1, 2);
        k.display(1, 3);
        a2.display(1, 4);
        s.display(1, 5);
        h.display(1, 6);
        A.display(1, 7);
        g.display(1, 8);
        a3.display(1, 9);
        r2.display(1, 10);
        w.display(1,11);
        a4.display(1, 12);
        l.display(1, 13);
        
        factory.size() ; 
    }
}