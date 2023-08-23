import java.util.Scanner;
public class Evenodd {

    public static void main(String[] args) {

        int num = 0;
        Scanner input = new Scanner(System.in);
        System.out.println("Enter a number: ");
        num = input.nextInt();
        if (num % 2 == 0) {
        	System.out.println(num + " is even.");
        }
        else {
        	System.out.println(num + " is odd.");
	}
 	}
 }
