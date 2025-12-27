package student ; 
import java.util.* ; 
import studentBuilder.*;

public class Student {
    String rollNo ; 
    int age ; 
    String name ; 
    int batch ; 
    String branch ; 
    String motherName ; 
    String fatherName ; 
    ArrayList<String> courses ; 
    int section ; 
    
    public Student(StudentBuilder builder){
        this.rollNo = builder.rollNo ; 
        this.age = builder.age ; 
        this.name = builder.name ; 
        this.batch = builder.batch ;
        this.branch = builder.branch ; 
        this.motherName = builder.motherName ; 
        this.fatherName = builder.fatherName ;
        this.courses = builder.courses ; 
        this.section = builder.section ; 
    }

    public String toString(){
        return String.format("RollNo : %s \n Age : %d \n Name : %s \n Batch: %s \n motherName : %s \n fatherName : %s, \n section : %d \n Courses : %s", 
                        rollNo, age, name, batch, motherName, fatherName, section, courses.toString() ) ;
    }
}