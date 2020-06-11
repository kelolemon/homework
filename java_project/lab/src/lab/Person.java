package lab;

import java.io.Serializable;

public class Person implements Serializable {
    protected String name, sex;
    protected int age;

    public Person(String name, String sex, int age){
        this.name = name;
        this.sex = sex;
        this.age = age;
    }

    public int getAge() {
        return age;
    }

    public String getName() {
        return name;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public String getSex() {
        return sex;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setSex(String sex) {
        this.sex = sex;
    }

    public void display(){
        System.out.printf("the Person info: name:%s, sex:%s, age:%d\n",
                this.name, this.sex, this.age);
    }

}
