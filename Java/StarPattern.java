import java.util.Scanner;
public class StarPattern {
    public static void main(String[] args) {
        int n = 0;
        Scanner input = new Scanner(System.in);
        System.out.print("\tInput the no of lines for your star pattern: ");
        n = input.nextInt();
        input.close();

        for (int i = 0; i <= n; i++) {
            System.out.println("\n");
            for (int j = 1; j <= i; j++) {
                System.out.print("*");
            }
        }
    }
}
