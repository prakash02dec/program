package user.service;
import java.util.* ; 

public class UserService {
    static ArrayList<User> userList = new ArrayList<>() ; 
    
    public UserService(){
        
    }
    
    public UserDoa addUser(UserDoa doa){
        User newUser = new User() ; 
        newUser.setUserId((int) new Random().nextInt(100-10) + 10 ) ; 
        newUser.setUsername(doa.getName()) ;
        newUser.setEmail(doa.getMail()) ;
        newUser.setPhoneNo(doa.getPhoneNo()) ;
        userList.add(newUser) ;
        return userObjToDoa(newUser) ;
    }

    public UserDoa getUser(int userId){
        for(User user : userList){
            if(user.getUserId() == userId){
                return userObjToDoa(user) ; 
            }
        }

        return null ; 
    }

    private UserDoa userObjToDoa(User user){
        UserDoa doa = new UserDoa() ; 
        doa.setId( user.getUserId() ) ; 
        doa.setName(user.getUsername()) ;
        doa.setMail(user.getEmail()) ;
        doa.setPhoneNo(user.getPhoneNo()) ;
        return doa ; 
    }

}
