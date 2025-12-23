import employee.* ; 

public class App {
    public static void main(){
        EmployeeDaoProxy supports = new EmployeeDaoProxy("SUPPORT") ; 
        supports.getEmployee() ; 
        try{
            supports.createEmpoyee() ; 
        }catch(Exception e){
            System.out.println(e + "\n") ;
        }
        EmployeeDaoProxy manager = new EmployeeDaoProxy("MANAGER") ;
        manager.createEmpoyee() ; 
        manager.getEmployee() ; 
        return ; 
    }
}