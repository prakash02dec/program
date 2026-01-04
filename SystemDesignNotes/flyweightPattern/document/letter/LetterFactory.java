package  letter ; 
import java.util.* ; 

public class LetterFactory {
    HashMap< String, DocumentCharacter> cache ; 

    public LetterFactory(){
        cache = new HashMap<>() ; 
    }

    public DocumentCharacter createLetter(char ch, int size, String font){
        StringBuffer key = new StringBuffer() ; 
        key.append(ch).append(size).append(font) ;
        
        if(cache.containsKey(key.toString())){
            return cache.get(key.toString()) ;
        }

        DocumentCharacter dch = new DocumentCharacter(size, font, ch) ;
        cache.put(key.toString(), dch) ;
        return dch ; 
    }

    public int size() {
        System.out.println("Size of the cache : " + cache.size()) ;
        return cache.size() ; 
    }
}