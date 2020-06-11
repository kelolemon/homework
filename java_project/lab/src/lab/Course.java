package lab;

import java.io.Serializable;

public class Course implements Serializable {
    private String cname;
    private String cid;
    private int cHour;
    public Course(String cname, String cid, int cHour){
        this.cHour = cHour;
        this.cid = cid;
        this.cname = cname;
    }

    public String getCid() {
        return cid;
    }

    public int getCHour() {
        return cHour;
    }

    public String getCname() {
        return cname;
    }

    public void setCHour(int cHour) {
        this.cHour = cHour;
    }

    public void setCid(String cid) {
        this.cid = cid;
    }

    public void setCname(String cname) {
        this.cname = cname;
    }

    public void display(){
        System.out.printf("The course info is cname:%s, cid:%s, chour:%d\n", this.cname, this.cid, this.cHour);
    }
}
