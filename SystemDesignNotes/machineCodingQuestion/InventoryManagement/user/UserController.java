package user;
import java.util.* ; 

public class UserController {
    static ArrayList<User> users = new ArrayList<>() ;
    public UserController(){

    }
    public void addUser( User u ){
        users.add(u) ;
    }
    public void removeUser( User u ){
        users.remove(u) ;
    } 
    public User getByUserId( int id ){
        for( User u : users ){
            if( u.getId() == id ){
                return u ;
            }
        }
        return null ;
    }
}
