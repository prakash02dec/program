package director;
import studentBuilder.*;

public class StudentRegisteration {
    public static StudentBuilder getBuilder(String type) throws Exception {
        switch (type) {
            case "computer":
                return new EngineeringStudentBuilder();
            case "electrical":
                return new ElectricalStudentBuilder();
            default:
                throw new Exception("Invalid student") ;
        }
    }
}
