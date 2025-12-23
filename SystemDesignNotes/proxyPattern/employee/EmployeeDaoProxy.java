package employee ; 
import java.util.* ; 

public class EmployeeDaoProxy implements EmployeeDao {
    private EmployeeDaoImp daoImp ;
    private final String clientRole  ; 

    public EmployeeDaoProxy(String role){
        daoImp = new EmployeeDaoImp() ; 
        clientRole = role ;
    }   

    @Override
    public void getEmployee(){
        if( !clientRole.equals("CUSTOMER")) 
            daoImp.getEmployee() ; 
        else 
            throw new RuntimeException("Access Denied") ;
    }

    @Override
    public void createEmpoyee(){
        if(clientRole.equals("ADMIN") || clientRole.equals("MANAGER") ) 
            daoImp.createEmpoyee() ; 
        else 
            throw new RuntimeException("Access Denied") ;
    } 
}