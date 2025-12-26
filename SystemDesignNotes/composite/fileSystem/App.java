public class App {
    public static void main(){
        Directory dir = new Directory("prakash") ;
        File file1 = new File("music1") ;
        dir.addContent(file1);
        File file2 = new File("music2") ;
        dir.addContent(file2);
        Directory program = new Directory( "program") ;
        dir.addContent(program);
        File cppQuestion1 = new File("cpp question1") ;
        program.addContent(cppQuestion1);
        File javaQuestion1 = new File("javaQuestion1") ;
        program.addContent(javaQuestion1);
        
        dir.ls() ; 

        return ; 
    }
}