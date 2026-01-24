public class App {
    public static void main(String[] args) {
        ApplicationConfigration applicationConfigration = new ApplicationConfigration("English", true, 16, "Dark");
        ConfigrationManager configrationManager = new ConfigrationManager(applicationConfigration);
        configrationManager.save();
        applicationConfigration.setLanguage("French");
        configrationManager.save();
        applicationConfigration.setEnabled(false);
        configrationManager.save();
        applicationConfigration.setFontsize(20);
        configrationManager.save();
        configrationManager.undo();
        configrationManager.undo();
    
    }
}
