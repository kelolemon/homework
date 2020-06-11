package lab;

public class TestMyFile {
    public static void main(String[] args) throws Exception {
        MyFile MyFileTest_tea = new MyFile("/Users/dengmengda/kelo/java_project/lab/src/lab/tea_info.data");
        Teacher tea = new Teacher("0000", "cz", "nan", 40, "professor");
        MyFileTest_tea.writefile(tea);
        //MyFileTest_tea.writefile((Teacher) null);
        Teacher[] tea_list = new Teacher[100];
        int tot = MyFileTest_tea.readfile(tea_list);
        for (int i = 1; i <= tot; i++) {
            tea_list[i - 1].display();
        }

        MyFile MyFileTest_stu = new MyFile("/Users/dengmengda/kelo/java_project/lab/src/lab/stu_info.data");
        Student stu = new Student("2018091620008", "dmd", "nan", 19, "cs");
        MyFileTest_stu.writefile(stu);
        //MyFileTest_stu.writefile((Student) null);
        Student[] stu_list = new Student[100];
        tot = MyFileTest_stu.readfile(stu_list);
        for (int i = 1; i <= tot ;i++) {
            stu_list[i - 1].display();
        }
    }
}
