package homework_4;

class Author {
    private String name;
    private String mail;
    private char generate;
    String getName(){
        return name;
    }
    private String getMail(){
        return mail;
    }
    private char getGenerate(){
        return generate;
    }
    Author(String n, String m, char g){
        name = n;
        mail = m;
        generate = g;
    }
    public String toString(){
        return this.getClass() + "[name = " + this.getName() + ", mail = " + this.getMail() +
                ", generate = " + this.getGenerate() + "]";
    }
}

public class Book {
    private String name;
    private Author author;
    private double price;
    private int qty = 0;
    private Book(String n, Author a, double p){
        name = n;
        author = a;
        price = p;
    }
    private Book(String n, Author a, double p, int q){
        name = n;
        author = a;
        price = p;
        qty = q;
    }
    private String getName(){
        return name;
    }
    private String getAuthor(){
        return author.toString();
    }
    private void setPrice(double p){
        price = p;
    }
    private double getPrice(){
        return price;
    }
    private void setQty(int q){
        qty = q;
    }
    private int getQty(){
        return qty;
    }
    private String getAuthor_name(){
        return author.getName();
    }
    public String toString() {
        return this.getClass() + "[name = " + this.getName() + ", authors = {" + author.toString() + "}, price = "
                + this.getPrice() + ", qty = " + this.getQty() + "]";
    }

    public static void main(String[] args) {
        Author a1 = new Author("srq", "srq@cetacis.dev", 'f');
        Book b1 = new Book("hhh", a1, 12, 10);
        b1.setPrice(127.1);
        System.out.println(b1.getAuthor());
        b1.setQty(12);
        System.out.println(b1.getAuthor_name());
        System.out.println(b1.toString());
    }
}
