/*
 * Author:	Dilpreet Chana
 * Title:	P1.java
 *
 * Description:	It's black magic, I ain't gotta explain shit.
		JK, this calculates interest for 3 years.
**/

public class P1 {
	public static void main(String[] args) {
		// Declare and initialize variables
		double val = 1000;
		double interest = 0.05;

		for (int i = 0; i < 3; i++) {
			val *= 1 + interest;  // Add compounded interest
			System.out.printf("year %d: $%.2f\n", i + 1, val);
		}
	}
}
