package lab;

import java.io.Serializable;

public class Schedule implements Serializable {
    private String classid, cid, tid, classroom;
    public Schedule(String classid, String cid, String tid, String classroom){
        this.classroom = classroom;
        this.tid = tid;
        this.cid = cid;
        this.classid = classid;
    }

    public void setCid(String cid) {
        this.cid = cid;
    }

    public String getCid() {
        return cid;
    }

    public void setTid(String tid) {
        this.tid = tid;
    }

    public String getTid() {
        return tid;
    }

    public String getClassid() {
        return classid;
    }

    public String getClassroom() {
        return classroom;
    }

    public void setClassid(String classid) {
        this.classid = classid;
    }

    public void setClassroom(String classroom) {
        this.classroom = classroom;
    }

    public void display(){
        System.out.printf("The schedule's info is: classid:%s, cid:%s, tid:%s, classroom:%s\n",
                this.classid, this.cid, this.tid, this.classroom);
    }
}
