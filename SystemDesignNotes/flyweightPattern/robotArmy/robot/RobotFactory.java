package robot ; 
import java.util.* ; 

public class RobotFactory {
    HashMap<String, Robot> mp ; 

    public RobotFactory(){
        mp = new HashMap<>() ; 
    }

    public Robot createRobot(String type){
        if(mp.containsKey(type))
            return mp.get(type)  ;
        
        Sprites sprite = new Sprites() ; 
        if(type.equals("humanoid") ){
            Robot robot = new HumanoidRobot(type , sprite) ;
            mp.put(type , robot) ;
            return robot ;
        }else if (type.equals("dog")) {
            Robot robot = new DogRobot(type , sprite) ;
            mp.put(type , robot) ;
            return robot ; 
        }

        throw new IllegalArgumentException("INVALID ROBOT TYPE ")    ;
    }

    public int size(){
        return mp.size(); 
    }

}