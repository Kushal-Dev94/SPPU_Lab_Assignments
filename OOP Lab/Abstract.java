/*
    Name: Kushal Kishor Shankhapal
    Roll No: 56
    Assignment No: 4

    Problem Statement: 
        Design a base class shape with two double type values and member functions to input the data
        and compute_area() for calculating area of shape. Derive two classes: triangle and rectangle. Make
        compute_area() as abstract function and redefine this function in the derived class to suit their
        requirements. Write a program that accepts dimensions of triangle/rectangle and display
        calculated area. Implement dynamic binding for given case study.
 */

abstract class Shape {
    double a, b;
    abstract void Compute_Area();
}

class Triangle extends Shape {
    Triangle(double base, double height) {
        this.a = base;
        this.b = height;
    }

    void Compute_Area() {
        System.out.println("Area of the Triangle is: " + (0.5 * a * b));
    }
}

class Rectangle extends Shape {
    Rectangle(double length, double breadth) {
        this.a = length;
        this.b = breadth;
    }

    void Compute_Area() {
        System.out.println("Area of the Rectangle is: " + (a * b));
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