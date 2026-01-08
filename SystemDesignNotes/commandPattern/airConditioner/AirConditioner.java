package airConditioner ;

public class AirConditioner {
    boolean on ; 
    int temperature ; 
    public AirConditioner(){
        on = false ; 
        temperature = 18 ; 
    }
    public AirConditioner(boolean on, int temperature){
        this.on = on ; 
        this.temperature = temperature ; 
    }

    public boolean isOn(){
        return on ; 
    }

    public void turnOn(){
        on = true; 
    }
    public void turnOff(){
        on = false ;
    }
    public void setTemperature(int temp){
        temperature = temp ; 
    }

    public int getTemperature(){
        return temperature ; 
    }

}