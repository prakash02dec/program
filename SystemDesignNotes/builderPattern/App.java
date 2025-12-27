import director.*;
import student.* ; 

public class App {
    public static void main(String args[]){
        try{
        Student computerEng = StudentRegisteration.getBuilder("computer")
                                .setName("Prakash")
                                .setAge(18)
                                .setBatch(2020)
                                .setBranch("CSE")
                                .setRollNo("20bcs099")
                                .setSection(1)
                                .setCourses()
                                .build() ; 
        System.out.println(computerEng.toString()) ;
        }catch(Exception e){
            System.out.println(e) ;
        }
    }
}
