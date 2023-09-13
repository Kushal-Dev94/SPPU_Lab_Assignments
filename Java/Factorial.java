import java.util.Scanner;
public class Factorial {

    public static void main(String[] args) {

        int num = 0;
        Scanner input = new Scanner(System.in);
        System.out.println("Enter a number: ");
        num = input.nextInt();
        input.close();
        long factorial = 1;
        for(int i = 1; i <= num; ++i)
        {
            // factorial = factorial * i;
            factorial *= i;
        }
        System.out.printf("Factorial of %d = %d\n", num, factorial);
    }
}
