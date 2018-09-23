import java.util.Scanner;
public class Fraction{
    public static void main(String[] args) {
	
    //blank string for skipping the "/" when useing the scanner
        String div;
        
	//initialized the scanner
        
		Scanner scan = new Scanner(System.in);
        
	//displays words
        
		System.out.print("Enter a fraction (a / b): ");
        
	//num1 as in the first numerator of the fractions is scanned where the a is typed
        
		int num1 = scan.nextInt();
        
	// skips over the "/"        
		div = scan.next("/");
        
	//den 1 stands for denominator 1
        
		int den1 = scan.nextInt();
       
	//asks for next fraction to be entered
        
		System.out.print("Enter another fraction (a / b):");
        
	//numerator 2
        
		int num2 = scan.nextInt();
        
	//skips "/"
        
		div = scan.next("/");
        
	//denominator 2
        
		int den2 = scan.nextInt();
        
        
	//finds common denominator
        
		int den3 = den1 * den2;
        
	//converts numerators to be compatible with the common denominator
        
		int numx = num1 * den2;
        
		int numy = num2 * den1;
        
	// add the numerators of the fractions together
        
		int num3 = numx + numy;
        
	//displays for the user the math
        
		System.out.println();
        
		System.out.println("The sum in fractions is");
        
		System.out.println( num1 + "/" + den1 + " + " + num2 + "/" + den2 + " = " + num3 + "/" + den3);
        
        //converts fractions to decimals
        
        float dec1 = (float) (num1) / (den1);
        float dec2 = (float) (num2) / (den2);
        
	//adds the decimals together
        float dec3 = (float) (dec1) + (dec2);
        
	//prints the decimal math for user
        System.out.println();
        System.out.println("The sum in decimals is");
        System.out.println( dec1 + " + " +dec2 + " = " + dec3);
        }
}