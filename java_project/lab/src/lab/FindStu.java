package lab;

public class FindStu {
    private String course_name;
    private String techer_name;
    private String classroom;
    private String classid;
    private String course_id;
    private String tid;

    public FindStu(){
        this.course_name = null;
        this.techer_name = null;
        this.classroom = null;
        this.classid = null;
        this.course_id = null;
        this.tid = null;
    }

    public String getTid() {
        return tid;
    }

    public void setTid(String tid) {
        this.tid = tid;
    }

    public String getCourse_id() {
        return course_id;
    }

    public void setCourse_id(String course_id) {
        this.course_id = course_id;
    }

    public String getClassid() {
        return classid;
    }

    public String getClassroom() {
        return classroom;
    }

    public String getCourse_name() {
        return course_name;
    }

    public String getTecher_name() {
        return techer_name;
    }

    public void setClassroom(String classroom) {
        this.classroom = classroom;
    }

    public void setCourse_name(String course_name) {
        this.course_name = course_name;
    }

    public void setTecher_name(String techer_name) {
        this.techer_name = techer_name;
    }

    public void setClassid(String classid) {
        this.classid = classid;
    }
}
