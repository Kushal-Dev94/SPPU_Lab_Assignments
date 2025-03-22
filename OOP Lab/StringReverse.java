import java.util.Scanner;
public class StringReverse {

    public static void main(String[] args) {

        StringBuilder str = new StringBuilder();
        Scanner input = new Scanner(System.in);
        System.out.println("Enter a string: ");
        str.append(input.next());
	str = str.reverse();
        System.out.println("The reversed string is: " + str);
        }
}
        
