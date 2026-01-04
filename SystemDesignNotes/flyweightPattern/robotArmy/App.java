import robot.* ; 

public class App {

    public static void main(){
        RobotFactory factory = new RobotFactory() ; 
        Robot robot1= factory.createRobot("dog") ;
        robot1.display(1,1);
        Robot robot2= factory.createRobot("dog") ;
        robot2.display(2,2);
        Robot robot3= factory.createRobot("humanoid") ;
        robot3.display(1,2);
        Robot robot4= factory.createRobot("humanoid") ;
        robot4.display(2,1);
        System.out.println("Size of the robot in graphics :" + factory.size()) ;
    }
}