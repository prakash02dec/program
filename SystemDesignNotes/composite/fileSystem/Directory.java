import java.util.* ; 

public class Directory implements FileSystemComponent{
    String name ; 
    ArrayList<FileSystemComponent>  content ; 

    public Directory(String name){
        this.name = name ; 
        content = new ArrayList<FileSystemComponent>() ; 
    }

    public void addContent(FileSystemComponent item){
        content.add(item) ;
    }

    public void removeContent(FileSystemComponent item){
        content.remove(item) ;
    }

    @Override
    public void ls(){
        System.out.println("Directory : " + name + " and content inside directory are below") ;
        for(FileSystemComponent item : content){
            item.ls() ; 
        }
    }
}