package studentBuilder ; 
import java.util.* ;  
import student.* ; 

public abstract class StudentBuilder {
    public String rollNo ; 
    public int age ; 
    public String name ; 
    public int batch ; 
    public String branch ; 
    public String motherName ; 
    public String fatherName ; 
    public ArrayList<String> courses ; 
    public int section ;
    
    public StudentBuilder(){
        courses = new ArrayList<>() ; 
    }

    public StudentBuilder setRollNo(String rollNo) {
        this.rollNo = rollNo;
        return this ;
    }
    public StudentBuilder setAge(int age) {
        this.age = age;
        return this ;
    }
    public StudentBuilder setName(String name) {
        this.name = name;
        return this ;
    }
    public StudentBuilder setBatch(int batch) {
        this.batch = batch;
        return this ;
    }
    public StudentBuilder setBranch(String branch) {
        this.branch = branch;
        return this ;
    }
    public StudentBuilder setMotherName(String motherName) {
        this.motherName = motherName;
        return this ;
    }
    public StudentBuilder setFatherName(String fatherName) {
        this.fatherName = fatherName;
        return this ;
    }
    public StudentBuilder setSection(int section) {
        this.section = section;
        return this ;
    } 
    
    public StudentBuilder addCourse(String course){
        courses.add(course) ;
        return this ; 
    }
    public abstract StudentBuilder setCourses() ; 

    public Student build(){
        return new Student(this) ;
    }

}