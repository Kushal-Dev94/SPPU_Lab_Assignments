import java.util.Scanner;
public class Prime {

    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);
        System.out.println("Enter a number: ");
        int num = input.nextInt();
		input.close();
		int flag = 0;

        for (int i = 2; i < num; i++) {
			if (num % i == 0) {
				System.out.println(num + " is prime");
				flag = 1;
				break;
			}
		}

		if (flag == 0) {
			System.out.println(num + " is not prime");
		}

	}
}

