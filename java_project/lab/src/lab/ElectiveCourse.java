package lab;

import java.io.Serializable;

public class ElectiveCourse implements Serializable {
    private String eid, sid, classid;
    public ElectiveCourse(String eid, String sid, String classid){
        this.eid = eid;
        this.sid = sid;
        this.classid = classid;
    }

    public void setClassid(String classid) {
        this.classid = classid;
    }

    public String getClassid() {
        return classid;
    }

    public void setSid(String sid) {
        this.sid = sid;
    }

    public String getSid() {
        return sid;
    }

    public String getEid() {
        return eid;
    }

    public void setEid(String eid) {
        this.eid = eid;
    }

    public void display() {
        System.out.printf("The electiveCourse' info is eid:%s, sid:%s, classid:%s\n",
                this.eid, this.sid, this.classid);
    }
}

