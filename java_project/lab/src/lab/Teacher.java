package lab;

import java.io.Serializable;

public class Teacher extends Person implements Serializable {
    private String tid;
    private String title;

    public Teacher(String tid, String name, String sex, int age, String title) {
        super(name, sex, age);
        this.tid = tid;
        this.title = title;
    }

    public String getTid() {
        return tid;
    }

    public String getTitle() {
        return title;
    }

    public void setTid(String tid) {
        this.tid = tid;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    @Override
    public void display() {
        System.out.printf("The teacher's info is : tid:%s, name:%s , sex:%s, age:%d, title:%s\n",
                this.tid, this.name, this.sex, this.age, this.title);
    }
}
