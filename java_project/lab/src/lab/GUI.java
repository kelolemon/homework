package lab;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.regex.Pattern;

public class GUI {

    private static boolean isNumeric(String str){
        Pattern pattern = Pattern.compile("[0-9]*");
        return pattern.matcher(str).matches();
    }

    public GUI(){
        JFrame frame = new JFrame("ElectiveCourse Management System");
        JButton add_teacher = new JButton("Add the teacher's data");
        JButton add_student = new JButton("Add student's data");
        JButton add_course = new JButton("Add course's data");
        JButton add_schedule = new JButton("Add schedule's data");
        JButton add_ElectiveCourse = new JButton("Add electivecourse's data");
        JButton search_stu_info = new JButton("search student info");
        JButton quit = new JButton("quit");

        JLabel notify = new JLabel("Please choose one option you want to do\n");
        frame.setSize(500, 500);
        frame.add(notify);
        frame.add(add_student);
        frame.add(add_teacher);
        frame.add(add_course);
        frame.add(add_schedule);
        frame.add(add_ElectiveCourse);
        frame.add(search_stu_info);
        frame.add(quit);
        frame.setLayout(new GridLayout(8,1,20,10));
        frame.setLocationRelativeTo(null);
        frame.setVisible(true);

        ActionListener listen_quit = new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent actionEvent) {
                System.exit(1);
            }
        };

        ActionListener listen_add_student = new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent actionEvent) {
                frame.setVisible(false);
                JFrame frame_add = new JFrame("Add the student's data");
                JPanel panel_add = new JPanel(new GridLayout(6, 2, 20, 10));
                JLabel notify = new JLabel("Please enter the follow info to add the student's data");
                JLabel notify_name = new JLabel("student's name");
                JLabel notify_id = new JLabel("student's id");
                JLabel notify_age = new JLabel("student's age");
                JLabel notify_sex = new JLabel("student's sex");
                JLabel notify_major = new JLabel("student's major");
                JTextField student_name = new JTextField(10);
                JTextField student_id = new JTextField(10);
                JTextField student_age = new JTextField(10);
                JTextField student_sex = new JTextField(10);
                JTextField student_major = new JTextField(10);
                JButton conf = new JButton("confirmed");
                JButton exit = new JButton("exit");
                frame_add.add(notify);
                panel_add.add(notify_name);
                panel_add.add(student_name);
                panel_add.add(notify_id);
                panel_add.add(student_id);
                panel_add.add(notify_age);
                panel_add.add(student_age);
                panel_add.add(notify_sex);
                panel_add.add(student_sex);
                panel_add.add(notify_major);
                panel_add.add(student_major);
                panel_add.add(conf);
                panel_add.add(exit);
                frame_add.add(panel_add);
                frame_add.setLayout(new FlowLayout());
                frame_add.setSize(500, 500);
                frame_add.setLocationRelativeTo(null);
                frame_add.setVisible(true);

                ActionListener listen_com = new ActionListener() {
                    @Override
                    public void actionPerformed(ActionEvent actionEvent) {
                        String sid = student_id.getText().trim();
                        String name = student_name.getText().trim();
                        String sex = student_sex.getText().trim();
                        if (!isNumeric(student_age.getText().trim())) {
                            JOptionPane.showMessageDialog(null, "age should be a number");
                            return;
                        }
                        int age = Integer.parseInt(student_age.getText().trim());
                        String major = student_major.getText().trim();
                        Student add_student = new Student(sid, name, sex, age, major);
                        MyFile input = new MyFile("student.data");
                        try {
                            input.writefile(add_student);
                        } catch (Exception e) {
                            e.printStackTrace();
                        }
                        JOptionPane.showMessageDialog(null, "Write student's info successfully");
                        frame.setVisible(true);
                        frame_add.setVisible(false);
                    }
                };

                ActionListener listen_exit = new ActionListener() {
                    @Override
                    public void actionPerformed(ActionEvent actionEvent) {
                        frame.setVisible(true);
                        frame_add.setVisible(false);
                    }
                };

                conf.addActionListener(listen_com);
                exit.addActionListener(listen_exit);
            }


        };

        ActionListener listen_add_teacher = new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent actionEvent) {
                frame.setVisible(false);
                JFrame frame_add = new JFrame("Add the teacher's data");
                JPanel panel_add = new JPanel(new GridLayout(6, 2, 20, 10));
                JLabel notify = new JLabel("Please enter the follow info to add the teacher's data");
                JLabel notify_name = new JLabel("teacher's name");
                JLabel notify_id = new JLabel("teacher's id");
                JLabel notify_age = new JLabel("teacher's age");
                JLabel notify_sex = new JLabel("teacher's sex");
                JLabel notify_title = new JLabel("teacher's title");
                JTextField teacher_name = new JTextField(10);
                JTextField teacher_id = new JTextField(10);
                JTextField teacher_age = new JTextField(10);
                JTextField teacher_sex = new JTextField(10);
                JTextField teacher_title = new JTextField(10);
                JButton conf = new JButton("confirmed");
                JButton exit = new JButton("exit");
                frame_add.add(notify);
                panel_add.add(notify_name);
                panel_add.add(teacher_name);
                panel_add.add(notify_id);
                panel_add.add(teacher_id);
                panel_add.add(notify_age);
                panel_add.add(teacher_age);
                panel_add.add(notify_sex);
                panel_add.add(teacher_sex);
                panel_add.add(notify_title);
                panel_add.add(teacher_title);
                panel_add.add(conf);
                panel_add.add(exit);
                frame_add.add(panel_add);

                frame_add.setLayout(new FlowLayout());
                frame_add.setSize(500, 500);
                frame_add.setLocationRelativeTo(null);
                frame_add.setVisible(true);

                ActionListener listen_com = new ActionListener() {
                    @Override
                    public void actionPerformed(ActionEvent actionEvent) {
                        String tid = teacher_id.getText().trim();
                        String name = teacher_name.getText().trim();
                        String sex = teacher_sex.getText().trim();
                        if (!isNumeric(teacher_age.getText().trim())) {
                            JOptionPane.showMessageDialog(null, "age should be a number");
                            return;
                        }
                        int age = Integer.parseInt(teacher_age.getText().trim());
                        String title = teacher_title.getText().trim();
                        Teacher add_teacher = new Teacher(tid, name, sex, age, title);
                        MyFile input = new MyFile("teacher.data");
                        try {
                            input.writefile(add_teacher);
                        } catch (Exception e) {
                            e.printStackTrace();
                        }
                        JOptionPane.showMessageDialog(null, "Write teacher's info successfully");
                        frame.setVisible(true);
                        frame_add.setVisible(false);
                    }
                };

                ActionListener listen_exit = new ActionListener() {
                    @Override
                    public void actionPerformed(ActionEvent actionEvent) {
                        frame.setVisible(true);
                        frame_add.setVisible(false);
                    }
                };

                conf.addActionListener(listen_com);
                exit.addActionListener(listen_exit);
            }
        };

        ActionListener listen_add_course = new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent actionEvent) {
                frame.setVisible(false);
                JFrame frame_add = new JFrame("Add the course's data");
                JPanel panel_add = new JPanel(new GridLayout(4, 2, 20, 10));
                JLabel notify = new JLabel("Please enter the follow info to add the course's data");
                JLabel notify_name = new JLabel("course's name");
                JLabel notify_id = new JLabel("course's id");
                JLabel notify_hour = new JLabel("course's hours");
                JTextField course_name = new JTextField(10);
                JTextField course_id = new JTextField(10);
                JTextField course_hour = new JTextField(10);

                JButton conf = new JButton("confirmed");
                JButton exit = new JButton("exit");
                frame_add.add(notify);
                panel_add.add(notify_name);
                panel_add.add(course_name);
                panel_add.add(notify_id);
                panel_add.add(course_id);
                panel_add.add(notify_hour);
                panel_add.add(course_hour);
                panel_add.add(conf);
                panel_add.add(exit);
                frame_add.add(panel_add);
                frame_add.setLayout(new FlowLayout());
                frame_add.setSize(500, 500);
                frame_add.setLocationRelativeTo(null);
                frame_add.setVisible(true);

                ActionListener listen_com = new ActionListener() {
                    @Override
                    public void actionPerformed(ActionEvent actionEvent) {
                        String cid = course_id.getText().trim();
                        String name = course_name.getText().trim();
                        if (!isNumeric(course_hour.getText().trim())) {
                            JOptionPane.showMessageDialog(null, "course hour should be a number");
                            return;
                        }
                        int hour = Integer.parseInt(course_hour.getText().trim());
                        Course add_course = new Course(name, cid, hour);
                        MyFile input = new MyFile("course.data");
                        try {
                            input.writefile(add_course);
                        } catch (Exception e) {
                            e.printStackTrace();
                        }
                        JOptionPane.showMessageDialog(null, "Write course's info successfully");
                        frame.setVisible(true);
                        frame_add.setVisible(false);
                    }
                };

                ActionListener listen_exit = new ActionListener() {
                    @Override
                    public void actionPerformed(ActionEvent actionEvent) {
                        frame.setVisible(true);
                        frame_add.setVisible(false);
                    }
                };

                conf.addActionListener(listen_com);
                exit.addActionListener(listen_exit);
            }
        };

        ActionListener listen_add_schedule = new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent actionEvent) {
                frame.setVisible(false);
                JFrame frame_add = new JFrame("Add the schedule's data");
                JPanel panel_add = new JPanel(new GridLayout(5, 2, 20, 10));
                JLabel notify = new JLabel("Please enter the follow info to add the schedule's data");
                JLabel notify_classid = new JLabel("schedule's class id");
                JLabel notify_cid = new JLabel("schedule's course id");
                JLabel notify_tid = new JLabel("schedule's teacher id");
                JLabel notify_classroom = new JLabel("schedule's classroom");
                JTextField schedule_cid = new JTextField(10);
                JTextField schedule_tid = new JTextField(10);
                JTextField schedule_classid = new JTextField(10);
                JTextField schedule_classroom = new JTextField(10);
                JButton conf = new JButton("confirmed");
                JButton exit = new JButton("exit");
                frame_add.add(notify);
                panel_add.add(notify_classid);
                panel_add.add(schedule_classid);
                panel_add.add(notify_cid);
                panel_add.add(schedule_cid);
                panel_add.add(notify_tid);
                panel_add.add(schedule_tid);
                panel_add.add(notify_classroom);
                panel_add.add(schedule_classroom);
                panel_add.add(conf);
                panel_add.add(exit);
                frame_add.add(panel_add);
                frame_add.setLayout(new FlowLayout());
                frame_add.setSize(500, 500);
                frame_add.setLocationRelativeTo(null);
                frame_add.setVisible(true);

                ActionListener listen_com = new ActionListener() {
                    @Override
                    public void actionPerformed(ActionEvent actionEvent) {
                        String classid = schedule_classid.getText().trim();
                        String cid = schedule_cid.getText().trim();
                        String tid = schedule_tid.getText().trim();
                        String classroom = schedule_classroom.getText().trim();

                        Schedule add_schedule = new Schedule(classid, cid, tid, classroom);
                        MyFile input = new MyFile("schedule.data");
                        try {
                            input.writefile(add_schedule);
                        } catch (Exception e) {
                            e.printStackTrace();
                        }
                        JOptionPane.showMessageDialog(null, "Write schedule's info successfully");
                        frame.setVisible(true);
                        frame_add.setVisible(false);
                    }
                };

                ActionListener listen_exit = new ActionListener() {
                    @Override
                    public void actionPerformed(ActionEvent actionEvent) {
                        frame.setVisible(true);
                        frame_add.setVisible(false);
                    }
                };

                conf.addActionListener(listen_com);
                exit.addActionListener(listen_exit);
            }
        };

        ActionListener listen_add_ElectiveCourse = new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent actionEvent) {
                frame.setVisible(false);
                JFrame frame_add = new JFrame("Add the electivecourse's data");
                JPanel panel_add = new JPanel(new GridLayout(4, 2, 20, 10));
                JLabel notify = new JLabel("Please enter the follow info to add the electivecourse's data");
                JLabel notify_eid = new JLabel("electivecourse's id");
                JLabel notify_sid = new JLabel("student's id");
                JLabel notify_classid = new JLabel("class id");

                JTextField electivecourse_eid = new JTextField(10);
                JTextField electivecourse_sid = new JTextField(10);
                JTextField electivecourse_classid = new JTextField(10);
                JButton conf = new JButton("confirmed");
                JButton exit = new JButton("exit");
                frame_add.add(notify);
                panel_add.add(notify_eid);
                panel_add.add(electivecourse_eid);
                panel_add.add(notify_sid);
                panel_add.add(electivecourse_sid);
                panel_add.add(notify_classid);
                panel_add.add(electivecourse_classid);
                panel_add.add(conf);
                panel_add.add(exit);
                frame_add.add(panel_add);
                frame_add.setLayout(new FlowLayout());
                frame_add.setSize(500, 500);
                frame_add.setLocationRelativeTo(null);
                frame_add.setVisible(true);

                ActionListener listen_com = new ActionListener() {
                    @Override
                    public void actionPerformed(ActionEvent actionEvent) {
                        String eid = electivecourse_eid.getText().trim();
                        String sid = electivecourse_sid.getText().trim();
                        String classid = electivecourse_classid.getText().trim();
                        ElectiveCourse add_electivecourse = new ElectiveCourse(eid, sid, classid);
                        MyFile input = new MyFile("ElectiveCourse.data");
                        try {
                            input.writefile(add_electivecourse);
                        } catch (Exception e) {
                            e.printStackTrace();
                        }
                        JOptionPane.showMessageDialog(null, "Write EelectiveCourse's info successfully");
                        frame.setVisible(true);
                        frame_add.setVisible(false);
                    }
                };

                ActionListener listen_exit = new ActionListener() {
                    @Override
                    public void actionPerformed(ActionEvent actionEvent) {
                        frame.setVisible(true);
                        frame_add.setVisible(false);
                    }
                };

                conf.addActionListener(listen_com);
                exit.addActionListener(listen_exit);
            }
        };

        ActionListener listen_search = new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent actionEvent) {
                frame.setVisible(false);
                JFrame search = new JFrame("search student's info");
                JPanel panel_search = new JPanel(new GridLayout(2, 2, 20, 10));
                JButton exit = new JButton("exit");
                JButton conf = new JButton("confirmed");

                search.setLayout(new FlowLayout());
                JLabel notify = new JLabel("please input the students' id");
                JTextField student_id = new JTextField(10);
                panel_search.add(notify);
                panel_search.add(student_id);
                panel_search.add(conf);
                panel_search.add(exit);
                search.add(panel_search);
                search.setSize(500, 500);
                search.setLocationRelativeTo(null);
                search.setVisible(true);

                ActionListener listen_exit = new ActionListener() {
                    @Override
                    public void actionPerformed(ActionEvent actionEvent) {
                        frame.setVisible(true);
                        search.setVisible(false);
                    }
                };

                ActionListener listen_con = new ActionListener() {
                    @Override
                    public void actionPerformed(ActionEvent actionEvent) {
                        search.setVisible(false);
                        String sid = student_id.getText().trim();
                        MyFile read_stu = new MyFile("student.data");
                        Student[] stu_list = new Student[10001];
                        int stu_tot = 0;
                        try {
                            stu_tot = read_stu.readfile(stu_list);
                        } catch (Exception e) {
                            e.printStackTrace();
                        }

                        boolean flag = false;

                        for (int i = 0; i < stu_tot; i++) {
                            if (stu_list[i].getSid().equals(sid)) {
                                flag = true;
                                break;
                            }
                        }

                        if (!flag) {
                            JOptionPane.showMessageDialog(null, "The student does not exist");
                            frame.setVisible(true);
                        } else {
                            boolean find = true;
                            int find_tot = 0;
                            FindStu[] find_std = new FindStu[10001];

                            // begin read ele list
                            MyFile read_ele = new MyFile("ElectiveCourse.data");
                            ElectiveCourse[] ele_list = new ElectiveCourse[10001];
                            int ele_tot = 0;
                            try {
                                ele_tot = read_ele.readfile(ele_list);
                            } catch (Exception e) {
                                e.printStackTrace();
                            }
                            // read ele list end.

                            // begin search ele list.
                            for (int i = 0; i < ele_tot; i++) {
                                if (ele_list[i].getSid().equals(sid)) {
                                    find_std[find_tot] = new FindStu();
                                    find_std[find_tot].setClassid(ele_list[i].getClassid());
                                    find_tot ++;
                                }
                            }

                            // search ele list end.

                            // read schedule .
                            MyFile read_sch = new MyFile("schedule.data");
                            Schedule[] sch_list = new Schedule[10001];
                            int sch_tot = 0;
                            try {
                                sch_tot = read_sch.readfile(sch_list);
                            } catch (Exception e) {
                                e.printStackTrace();
                            }
                            // schedule end.

                            // search schedule list
                            for (int i = 0;i < sch_tot; i++) {
                                for (int j = 0;j < find_tot; j++) {
                                    if (sch_list[i].getClassid().equals(find_std[j].getClassid())) {
                                        find_std[j].setClassroom(sch_list[i].getClassroom());
                                        find_std[j].setCourse_id(sch_list[i].getCid());
                                        find_std[j].setTid(sch_list[i].getTid());
                                    }
                                }
                            }
                            // search schedule end.

                            // begin read cou list
                            MyFile read_cou = new MyFile("course.data");
                            Course[] cou_list = new Course[10001];
                            int cou_tot = 0;
                            try {
                                cou_tot = read_cou.readfile(cou_list);
                            } catch (Exception e) {
                                e.printStackTrace();
                            }
                            // read cou list end.

                            // search cou list
                            for (int i = 0;i < cou_tot; i++) {
                                for (int j = 0;j < find_tot; j++) {
                                    if (cou_list[i].getCid().equals(find_std[j].getCourse_id())) {
                                        find_std[j].setCourse_name(cou_list[i].getCname());
                                    }
                                }
                            }
                            // search cou list end.

                            // begin read teacher list
                            MyFile read_tea = new MyFile("teacher.data");
                            Teacher[] tea_list = new Teacher[10001];
                            int tea_tot = 0;
                            try {
                                tea_tot = read_tea.readfile(tea_list);
                            } catch (Exception e) {
                                e.printStackTrace();
                            }
                            // read tea list end.

                            // search tea list
                            for (int i = 0;i < tea_tot; i++) {
                                for (int j = 0;j < find_tot; j++) {
                                    if (tea_list[i].getTid().equals(find_std[j].getTid())) {
                                        find_std[j].setTecher_name(tea_list[i].getName());
                                    }
                                }
                            }
                            // search tea list end.
                            if (find_tot == 0) {
                                JOptionPane.showMessageDialog(null, "Can not find other info!");
                                frame.setVisible(true);
                            } else {
                                JFrame find_suc = new JFrame("find successfully");
                                JLabel notify = new JLabel("The student's elective info are as follows:");
                                JLabel student_id = new JLabel(sid);
                                JPanel info = new JPanel(new GridLayout(find_tot * 5 + 2,2));
                                JLabel cou_name = new JLabel("the course's name is:");
                                JLabel tea_name = new JLabel("the teacher's name is:");
                                JLabel class_name = new JLabel("the class room is:");
                                for (int i = 0;i < find_tot; i++) {
                                    info.add(new Label("" + (i + 1) + "."));
                                    info.add(new Label("elective info is:"));
                                    info.add(new Label("---"));
                                    info.add(new Label("---"));
                                    info.add(new Label("the course's name is:"));
                                    info.add(new Label(find_std[i].getCourse_name()));
                                    info.add(new Label("the teacher's name is:"));
                                    info.add(new Label(find_std[i].getTecher_name()));
                                    info.add(new Label("the class room is:"));
                                    info.add(new Label(find_std[i].getClassroom()));
                                }
                                JButton ok = new JButton("Confirmed");
                                info.add(ok);
                                find_suc.add(notify);
                                find_suc.add(student_id);
                                find_suc.add(info);
                                find_suc.setLayout(new FlowLayout());
                                find_suc.setSize(500, 500);
                                find_suc.setLocationRelativeTo(null);
                                find_suc.setVisible(true);

                                ActionListener listen_ok = new ActionListener() {
                                    @Override
                                    public void actionPerformed(ActionEvent actionEvent) {
                                        find_suc.setVisible(false);
                                        frame.setVisible(true);
                                    }
                                };

                                ok.addActionListener(listen_ok);
                            }

                        }
                    }
                };

                conf.addActionListener(listen_con);
                exit.addActionListener(listen_exit);
            }
        };
        add_student.addActionListener(listen_add_student);
        quit.addActionListener(listen_quit);
        add_teacher.addActionListener(listen_add_teacher);
        add_course.addActionListener(listen_add_course);
        add_schedule.addActionListener(listen_add_schedule);
        add_ElectiveCourse.addActionListener(listen_add_ElectiveCourse);
        search_stu_info.addActionListener(listen_search);
    }

}
