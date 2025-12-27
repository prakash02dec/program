package studentBuilder;

public class EngineeringStudentBuilder  extends StudentBuilder {
    @Override
    public StudentBuilder setCourses(){
        courses.add("programming") ;
        courses.add("dataStructure") ;
        courses.add("DBMS") ;
        courses.add("ComputerNetwork") ;
        return this ; 
    }
}
