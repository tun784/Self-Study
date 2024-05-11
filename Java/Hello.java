import java.util.Scanner;

public class Hello {
	public static void main(String[] args) {
		int numA = 5, numB = 10;
		int numC = numA + numB;
		int numD = numA - numB;
		int numE = numB * numA;
		double numF = (double)numA / numB;
		System.out.println(numA + " and " + numB + ": " + numC + " " + numD + " " + numE + " " + numF);

		int age = 18;
		if (age >= 18)
			System.out.println("You are an adult");
		else
			System.out.println("You are a child");

		int i;
		for (i = 0; i < 5; i++)
			System.out.print(i + "-");
		System.out.println("");

		i = 0;
		while (i < 10){
			System.out.print(i + "_");
			i++;
		}
		System.out.println("");

		i = 0;
		do {
			System.out.print(i + " ");
			i++;
		} while (i < 15);
		System.out.println("");

		Scanner scan = new Scanner(System.in);
		System.out.print("What's your name: ");
		String name = scan.nextLine();
		System.out.println("Hello " + name + " !");
		scan.close();
	}
}