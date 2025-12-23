package employee ; 

public class EmployeeDaoImp implements EmployeeDao{

    @Override
    public void getEmployee(){
        System.out.println("Getting the Employee from the database") ;
    }
    @Override
    public void createEmpoyee(){
        System.out.println("Creating the Employee in the Database") ;
    } 
}