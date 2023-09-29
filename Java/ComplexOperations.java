/*
    Name: Kushal Kishor Shankhapal
    Roll No: 56
    Assignment No: 1

    Problem Statement: 
        Design a class ‘Complex ‘with data members for real and imaginary part. Provide default and
        Parameterized constructors. Write a program to perform arithmetic operations of two complex
        numbers.
*/

import java.util.Scanner;

public class ComplexOperations {
    static void getInput() {
        int a1, a2, b1, b2, d, a, b;
        char operator;

        System.out.print("\tInput your first complex no: a + bi\n\ta: ");
        Scanner input = new Scanner(System.in);
        a1 = input.nextInt();
        System.out.print("\tb: ");
        b1 = input.nextInt();
        System.out.print("\tInput your second complex no: a + bi\n\ta: ");
        a2 = input.nextInt();
        System.out.print("\tb: ");
        b2 = input.nextInt();

        System.out.print("\tChoose an operator: +, -, *, or /: ");
        operator = input.next().charAt(0);
        input.close();

        switch (operator) {

            case '+':
                a = a1 + a2;
                b = b1 + b2;
                System.out.format("\tThe addition of the two complex numbers is: \n\t(%d + %di) + (%d + %di) = (%d + %di)", a1, b1, a2, b2, a, b);
                break;

            case '-':
                a = a1 - a2;
                b = b1 - b2;
                System.out.format("\tThe subtraction of the two complex numbers is: \n\t(%d + %di) - (%d + %di) = (%d + %di)", a1, b1, a2, b2, a, b);
                break;

            case '*':
                a = (a1 * a2) - (b1 * b2);
                b = (a1 * b2) + (b1 * a2);
                System.out.format("\tThe multiplication of the two complex numbers is: \n\t(%d + %di) * (%d + %di) = (%d + %di)", a1, b1, a2, b2, a, b);
                break;

            case '/':
                d = (a2 * a2) + (b2 * b2);
                a = ((a1 * a2) + (b1 * b2)) / d;
                b = ((a2 * b1) - (a1 * b2)) / d;
                System.out.format("\tThe Division of the two complex numbers is: \n\t(%d + %di) * (%d + %di) = (%d + %di)", a1, b1, a2, b2, a, b);
                break;

            default:
                System.out.println("Invalid operator!");
                break;
        }

    }

    public static void main(String[] args) {
        getInput();
    }
}

/*
    Output 1: (Addition)

	Input your first complex no: a + bi
	a: 4
	b: 2
	Input your second complex no: a + bi
	a: 2
	b: 1
	Choose an operator: +, -, *, or /: +
	The addition of the two complex numbers is:
	(4 + 2i) + (2 + 1i) = (6 + 3i)


    Output 2: (Subtraction)

    Input your first complex no: a + bi
	a: 4
	b: 2
	Input your second complex no: a + bi
	a: 2
	b: 1
	Choose an operator: +, -, *, or /: -
	The subtraction of the two complex numbers is:
	(4 + 2i) - (2 + 1i) = (2 + 1i)


	Output 3: (Multiplication)

	Input your first complex no: a + bi
	a: 4
	b: 2
	Input your second complex no: a + bi
	a: 2
	b: 1
	Choose an operator: +, -, *, or /: *
	The multiplication of the two complex numbers is:
	(4 + 2i) * (2 + 1i) = (6 + 8i)

    
	Output 4: (Division)

	Input your first complex no: a + bi
	a: 4
	b: 2
	Input your second complex no: a + bi
	a: 2
	b: 1
	Choose an operator: +, -, *, or /: /
	The Division of the two complex numbers is:
	(4 + 2i) * (2 + 1i) = (2 + 0i)
*/