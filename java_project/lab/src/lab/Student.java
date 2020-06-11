package lab;

import java.io.Serializable;

public class Student extends Person implements Serializable {
    private String sid;
    private String major;

    public Student(String sid, String name, String sex, int age, String major) {
        super(name, sex, age);
        this.sid = sid;
        this.major = major;
    }

    public String getSid() {
        return sid;
    }

    public String getMajor() {
        return major;
    }

    public void setSid(String sid) {
        this.sid = sid;
    }

    public void setMajor(String major) {
        this.major = major;
    }

    @Override
    public void display() {
        System.out.printf("The student's info is : sid:%s, name:%s, sex:%s, age:%d, major:%s\n",
                this.sid, this.name, this.sex, this.age, this.major);
    }

}
