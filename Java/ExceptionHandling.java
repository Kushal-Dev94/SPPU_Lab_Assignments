/*
    Name: Kushal Kishor Shankhapal
    Roll No: 56
    Assignment No: 6

    Problem Statement: 
        Implement a program to handle Arithmetic exception, Array Index Out Of Bounds.
        The user enters two numbers Num1 and Num2. The division of Num1 and Num2 is displayed. If Num1
        and Num2 were not integers, the program would throw a Number Format Exception. If Num2 were zero,
        the program would throw an Arithmetic Exception. Display the exception
*/

import java.util.InputMismatchException;
import java.util.Scanner;

public class ExceptionHandling {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        try {
            System.out.print("Enter Num1 (an integer): ");
            int num1 = scanner.nextInt();

            System.out.print("Enter Num2 (an integer): ");
            int num2 = scanner.nextInt();

            int result = num1 / num2;
            System.out.println("Result of Num1 / Num2 = " + result);

        } catch (InputMismatchException e) {
            System.out.println("Number Format Exception: Input is not an integer.");
        } catch (ArithmeticException e) {
            System.out.println("Arithmetic Exception: Division by zero is not allowed.");
        } catch (Exception e) {
            System.out.println("Exception: " + e.getMessage());
        } finally {
            scanner.close();
        }
    }
}

/*
    Output 1:

    Enter Num1 (an integer): 2  
    Enter Num2 (an integer): 1.5
    Number Format Exception: Input is not an integer.


    Output 2:

    Enter Num1 (an integer): 5
    Enter Num2 (an integer): 0
    Arithmetic Exception: Division by zero is not allowed.
*/