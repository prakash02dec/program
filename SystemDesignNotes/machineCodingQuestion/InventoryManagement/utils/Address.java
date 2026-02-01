package utils;

public class Address {
    private int pinCode;
    private String city;
    private String state;

    public Address(String location) {
        String[] parts = location.split(", ");
        this.city = parts[0];
        this.state = parts[1];
        this.pinCode = Integer.parseInt(parts[2]);
    }

    public String getLocation() {
        return this.city + ", " + this.state + ", " + this.pinCode;
    }
    public int getPinCode() {
        return this.pinCode;
    }
    public String getCity() {
        return this.city;
    }
    public String getState() {
        return this.state;
    }  
       
    @Override
    public String toString() {
        return getLocation();
    }       
}
