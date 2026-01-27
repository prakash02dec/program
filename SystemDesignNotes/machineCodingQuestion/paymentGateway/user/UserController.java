package user;
import user.service.* ;

public class UserController {
    UserService userService ;
    public UserController(){
        userService = new UserService() ; 
    }

    public UserDoa addUser(UserDoa doa){
        return userService.addUser(doa) ;
    }

    public UserDoa getUser(int userId){
        return userService.getUser(userId) ;
    }
}
