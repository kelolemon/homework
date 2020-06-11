package homework_5;

import java.util.SplittableRandom;

class person {
    private String name;
    private String address;
    person(String n, String a){
        name = n;
        address = a;
    }

    private String getName(){
        return name;
    }
    private String getAddress(){
        return address;
    }
    private void setAddress(String a){
        address = a;
    }
    public String toString() {
        return this.getClass() + "[name = " + this.getName() + ", address = " + this.getAddress() + "]";
    }
}

class student extends person {
    private int year;
    private double fee;
    private String program;
    public student(String n, String a, String p, int y, double f) {
        super(n, a);
        year = y;
        program = p;
        fee = f;
    }
    private String getProgram(){
        return program;
    }
    private int getYear(){
        return year;
    }
    private double getFee(){
        return fee;
    }
    private void setYear(int y){
        year = y;
    }
    private void setFee(double f){
        fee = f;
    }
    private void setProgram(String p){
        program = p;
    }
    public String toString() {
        return this.getClass() + "[" + super.toString() + ", program = " + this.getProgram() + ", year = " + this.getYear() + ", fee = " + this.getFee() + "]";
    }
}

class staff extends person {
    private String school;
    private double pay;
    public staff(String n, String a, String s, double p){
        super(n, a);
        school = s;
        pay = p;
    }
    private String getSchool(){
        return school;
    }
    private double getPay(){
        return pay;
    }
    private void setSchool(String s){
        school = s;
    }
    private void setPay(double p){
        pay = p;
    }
    public String toString(){
        return this.getClass() + "[" + super.toString() + ", school = " + this.getSchool() + ", pay = " + this.getPay() + "]";
    }
}
public class Main {

    public static void main(String[] args) {
	    student s1 = new student("dmd", "jiangsu", "cs", 4, 123.3);
	    System.out.println(s1.toString());
	    staff s2 = new staff("cz", "chengdu", "uestc", 123123.123);
	    System.out.println(s2.toString());
    }
}
