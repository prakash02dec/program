public class File implements FileSystemComponent{
    String name ; 

    public File(String name){
        this.name = name ; 
    }

    @Override
    public void ls(){
        System.out.println("File : " + name) ;
    }
}