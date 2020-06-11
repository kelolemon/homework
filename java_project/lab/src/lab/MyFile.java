package lab;

import java.io.*;

public class MyFile {
    private File file;

    public MyFile(String filename){
        this.file = new File(filename);
    }

    public File getFile() {
        return file;
    }

    public void setFile(File file) {
        this.file = file;
    }

    public void writefile(Student stu) throws Exception {
        FileOutputStream file_out = new FileOutputStream(file, true);
        if (file.length() == 0) {
            ObjectOutputStream out = new ObjectOutputStream(file_out);
            out.writeObject(stu);
            out.flush();
            out.close();
        } else {
            MyObjectOutputStream out = new MyObjectOutputStream(file_out);
            out.writeObject(stu);
            out.flush();
            out.close();
        }
    }

    public void writefile(Person per) throws Exception {
        FileOutputStream file_out = new FileOutputStream(file, true);
        if (file.length() == 0) {
            ObjectOutputStream out = new ObjectOutputStream(file_out);
            out.writeObject(per);
            out.flush();
            out.close();
        } else {
            MyObjectOutputStream out = new MyObjectOutputStream(file_out);
            out.writeObject(per);
            out.flush();
            out.close();
        }
    }

    public void writefile(Course cou) throws Exception {
        FileOutputStream file_out = new FileOutputStream(file, true);
        if (file.length() == 0) {
            ObjectOutputStream out = new ObjectOutputStream(file_out);
            out.writeObject(cou);
            out.flush();
            out.close();
        } else {
            MyObjectOutputStream out = new MyObjectOutputStream(file_out);
            out.writeObject(cou);
            out.flush();
            out.close();
        }
    }

    public void writefile(Teacher tea) throws Exception {
        FileOutputStream file_out = new FileOutputStream(file, true);
        if (file.length() == 0) {
            ObjectOutputStream out = new ObjectOutputStream(file_out);
            out.writeObject(tea);
            out.flush();
            out.close();
        } else {
            MyObjectOutputStream out = new MyObjectOutputStream(file_out);
            out.writeObject(tea);
            out.flush();
            out.close();
        }
    }

    public void writefile(ElectiveCourse ele) throws Exception {
        FileOutputStream file_out = new FileOutputStream(file, true);
        if (file.length() == 0) {
            ObjectOutputStream out = new ObjectOutputStream(file_out);
            out.writeObject(ele);
            out.flush();
            out.close();
        } else {
            MyObjectOutputStream out = new MyObjectOutputStream(file_out);
            out.writeObject(ele);
            out.flush();
            out.close();
        }
    }

    public void writefile(Schedule sch) throws Exception {
        FileOutputStream file_out = new FileOutputStream(file, true);
        if (file.length() == 0) {
            ObjectOutputStream out = new ObjectOutputStream(file_out);
            out.writeObject(sch);
            out.flush();
            out.close();
        } else {
            MyObjectOutputStream out = new MyObjectOutputStream(file_out);
            out.writeObject(sch);
            out.flush();
            out.close();
        }
    }

    public int readfile(Student[] stu) throws Exception {
        FileInputStream file_in = new FileInputStream(file);
        ObjectInputStream in = new ObjectInputStream(file_in);
        int tot = 0;
        try{
            for (Student stu_in; (stu_in = (Student) in.readObject()) != null;) {
                stu[tot++] = stu_in;
            }
        } catch (Exception ignore) {

        }
        return tot;
    }

    public int readfile(Person[] per) throws Exception {
        FileInputStream file_in = new FileInputStream(file);
        ObjectInputStream in = new ObjectInputStream(file_in);
        int tot = 0;
        try {
            for (Person per_in; (per_in = (Person) in.readObject()) != null;) {
                per[tot++] = per_in;
            }
        } catch (Exception ignore) {

        }
        return tot;
    }

    public int readfile(Course[] cou) throws Exception {
        FileInputStream file_in = new FileInputStream(file);
        ObjectInputStream in = new ObjectInputStream(file_in);
        int tot = 0;
        try {
            for (Course cou_in; (cou_in = (Course) in.readObject()) != null;) {
                cou[tot++] = cou_in;
            }
        } catch (Exception ignore) {

        }
        return tot;
    }

    public int readfile(Teacher[] tea) throws Exception {
        FileInputStream file_in = new FileInputStream(file);
        ObjectInputStream in = new ObjectInputStream(file_in);
        int tot = 0;
        try {
            for (Teacher tea_in; (tea_in = (Teacher) in.readObject()) != null;) {
                tea[tot++] = tea_in;
            }
        } catch (Exception ignore) {

        }
        return tot;
    }

    public int readfile(Schedule[] sch) throws Exception {
        FileInputStream file_in = new FileInputStream(file);
        ObjectInputStream in = new ObjectInputStream(file_in);
        int tot = 0;
        try {
            for (Schedule sch_in; (sch_in = (Schedule) in.readObject()) != null;) {
                sch[tot++] = sch_in;
            }
        } catch (Exception ignore) {

        }
        return tot;
    }

    public int readfile(ElectiveCourse[] ele) throws Exception {
        FileInputStream file_in = new FileInputStream(file);
        ObjectInputStream in = new ObjectInputStream(file_in);
        int tot = 0;
        try {
            for (ElectiveCourse ele_in; (ele_in = (ElectiveCourse) in.readObject()) != null;) {
                ele[tot++] = ele_in;
            }
        } catch (Exception ignore) {

        }
        return tot;
    }

}
