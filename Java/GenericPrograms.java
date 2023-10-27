import java.util.Scanner;

class GenericPrograms {
    static <N> void evenOdd(int no) {
        if (no % 2 == 0) {
            System.out.println(no + " is Even.");
        } else {
            System.out.println(no + " is Odd.");
        }
    }

    static <S> void palindrome(String s) {
        String reversed_string = "";

        for (int i = 0; i < s.length(); i++) {
            reversed_string = s.charAt(i) + reversed_string;
        }

        if (s.equals(reversed_string)) {
            System.out.println(s + " is a Palindrome.");
        }

        else {
            System.out.println(s + " is not a Palindrome.");
        }
    }

    static <N> void primeChecker(int n) {
        boolean isPrime = true;

        for (int i = 2; i < n; i++) {
            if (n % i == 0) {
                System.out.println(n + " is not Prime.");
                isPrime = false;
                break;
            }
        }

        if (isPrime) {
            System.out.println(n + " is Prime.");
        }
    }

    public static void main(String args[]) {
        boolean isExit = false;
        int selection;
        Scanner input = new Scanner(System.in);
        while (!isExit) {
            System.out.println("1. Check if a number is Even or Odd.");
            System.out.println("2. Check if a string is Palindrome or not.");
            System.out.println("3. Check if a number is Prime or not.");
            System.out.println("4. Exit.");
            System.out.print("Enter your choice: ");
            selection = input.nextInt();

            switch (selection) {
                case 1:
                    System.out.print("Enter a number to check whether its Even or Odd: ");
                    evenOdd(input.nextInt());
                    break;

                case 2:
                    System.out.print("Enter a string to check whether its a Palindrome or not: ");
                    palindrome(input.next());
                    break;

                case 3:
                    System.out.print("Enter a number to check whether its Prime or not: ");
                    primeChecker(input.nextInt());
                    break;

                case 4:
                    isExit = true;
                    break;
            }
            input.close();
        }
    }
}