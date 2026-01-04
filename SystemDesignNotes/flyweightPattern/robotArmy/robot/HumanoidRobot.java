package robot ; 

public class HumanoidRobot implements Robot {
    String type ;
    Sprites sprite ; 

    public HumanoidRobot(String type, Sprites sprite){
        this.type = type ; 
        this.sprite = sprite  ;
    }

    public String getType() {
        return type;
    }

    public Sprites getSprite() {
        return sprite;
    }

    @Override
    public void display(int x, int y){
        System.out.println("displaying " + type + "at x :" + x + " and y : " + y) ;
    }

}