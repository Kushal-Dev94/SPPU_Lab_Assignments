import java.util.Scanner;
public class MultiplicationTable {

    public static void main(String[] args) {

        int num = 0;
        Scanner input = new Scanner(System.in);
        System.out.print("Which number's multiplication table you want?: ");
        num = input.nextInt();
        for (int i = 1; i <= 10; i++) {
            System.out.println(num + " * " + i + " = " + num * i);
        }
    }

}