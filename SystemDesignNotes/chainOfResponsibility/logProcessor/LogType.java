package logProcessor;

public enum LogType {
    INFO(1),
    DEBUG(2),
    ERROR(3),
    FATAL(4) ;

    private int level ; 

    LogType(int level){
        this.level = level ; 
    }

    public int getLevel() {
        return this.level ; 
    }
}
