public class ConfigrationMemento {
    String language;
    boolean enabled;
    int fontsize;
    String theme;
    public ConfigrationMemento(String language, boolean enabled, int fontsize, String theme) {
        this.language = language;
        this.enabled = enabled;
        this.fontsize = fontsize;
        this.theme = theme;
    }

    public String getLanguage() {
        return language;
    }
    public boolean isEnabled() {
        return enabled;
    }
    public int getFontsize() {
        return fontsize;
    }
    public String getTheme() {
        return theme;
    }
}