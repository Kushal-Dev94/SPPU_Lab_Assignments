/*
    Name: Kushal Kishor Shankhapal
    Roll No: 56
    Assignment No: 1
 */

abstract class Shape {
    double a, b;
    public void Compute_Area(){

    }
}

class Triangle extends Shape {
    Triangle(double base, double height) {
        this.a = base;
        this.b = height;
        Compute_Area(a, b);
    }

    void Compute_Area(double base, double height) {
        System.out.println("Area of the Triangle is: " + (0.5 * base * height));
    }
}

class Rectangle extends Shape {
    Rectangle(double length, double breadth) {
        this.a = length;
        this.b = breadth;
        Compute_Area(a, b);
    }

    void Compute_Area(double length, double breadth) {
        System.out.println("Area of the Rectangle is: " + (length * breadth));
    }
}

public class Abstract {
    public static void main(String[] args) {
        Shape t = new Triangle(5, 10);
        t.Compute_Area();
        Shape r = new Rectangle(5, 10);
        r.Compute_Area();
    }
}

/*
    Output:
    Area of the Triangle is: 25.0
    Area of the Rectangle is: 50.0 
 */