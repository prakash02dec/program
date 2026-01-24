import java.util.*;

public class ConfigrationManager {
    Stack<ConfigrationMemento> history; 
    ApplicationConfigration applicationConfigration;
    public ConfigrationManager(ApplicationConfigration applicationConfigration) {
        this.history = new Stack<>();
        this.applicationConfigration = applicationConfigration;
    }
    public void save() {
        ConfigrationMemento memento = applicationConfigration.save();
        System.out.println("[INFO] configration saved to " +  applicationConfigration) ; 
        history.push(memento);
    }
    public void undo() {
        if (history.size() > 1) {
            history.pop();
            ConfigrationMemento memento = history.peek();
            applicationConfigration.restore(memento);
            System.out.println("[INFO] configration restored to " + applicationConfigration ) ; 
        } else {
            System.out.println("[INFO] this is the last default configration");
        }
    }
}