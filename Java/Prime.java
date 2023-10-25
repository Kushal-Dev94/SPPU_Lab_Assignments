import java.util.Scanner;
public class Prime {

    public static void main(String[] args) {

        int num = 0;
        Scanner input = new Scanner(System.in);
        System.out.println("Enter a number: ");
        num = input.nextInt();
        for (int i = 2; i < num; i++) {
 		if (num % i == 0) {
 			System.out.println(num + " is prime");
 			break;
 		}
 		else
 		{
 			System.out.println(num + " is not prime");
 			break;
 		}
	}
	}
	}

