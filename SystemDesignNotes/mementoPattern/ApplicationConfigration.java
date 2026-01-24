public class ApplicationConfigration {
    String language ; 
    boolean enabled ; 
    int fontsize ; 
    String theme ; 
    public ApplicationConfigration(String language, boolean enabled, int fontsize, String theme) {
        this.language = language;
        this.enabled = enabled;
        this.fontsize = fontsize;
        this.theme = theme;
    }
    public void setLanguage(String language) {
        this.language = language;
    }
    public void setEnabled(boolean enabled) {
        this.enabled = enabled;
    }
    public void setFontsize(int fontsize) {
        this.fontsize = fontsize;
    }
    public void setTheme(String theme) {
        this.theme = theme;
    }
    public ConfigrationMemento save() {
        return new ConfigrationMemento(language, enabled, fontsize, theme);
    }
    public void restore(ConfigrationMemento memento) {
        this.language = memento.getLanguage();
        this.enabled = memento.isEnabled();
        this.fontsize = memento.getFontsize();
        this.theme = memento.getTheme();
    }
    public String toString() {
        return "Language: " + language + ", Enabled: " + enabled + ", Fontsize: " + fontsize + ", Theme: " + theme;
    }
}