import java.util.Scanner;

public class ComplexOperations {
    static void getInput() {
        int a1 = 0, a2 = 0, b1 = 0, b2 = 0, a = 0, b = 0;
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
                System.out.format("\tThe addition of two complex numbers is: \n(%d + %di) + (%d + %di) = (%d + %di)", a1, b1, a2, b2, a, b);
                break;
      
            case '-':
                a = a1 - a2;
                b = b1 - b2;
                System.out.format("\tThe substraction of two complex numbers is: \n(%d + %di) - (%d + %di) = (%d + %di)", a1, b1, a2, b2, a, b);
                break;
      
            case '*':
                a = (a1 * a2) - (b1 * b2);
                b = (a1 * b2) + (b1 * a2);
                System.out.format("\tThe multiplication of two complex numbers is: \n(%d + %di) * (%d + %di) = (%d + %di)", a1, b1, a2, b2, a, b);
                break;
      
            case '/':

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