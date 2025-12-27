package studentBuilder ; 

public class ElectricalStudentBuilder  extends StudentBuilder {
    @Override
    public StudentBuilder setCourses(){
        courses.add("ComputerArchitecture") ;
        courses.add("VSLI") ;
        courses.add("ElectornicComponents") ;
        courses.add("AssemblyProgramming") ;
        return this ; 
    }
}
