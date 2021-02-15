package FrequentPrograms;

import java.util.Scanner;

public class PerfectNumberUsingClass {
	private static Scanner sc;
	public static void main(String[] args) {
		int Number, Sum = 0;
		sc = new Scanner(System.in);
		
		System.out.println("Please Enter any Number: ");
		Number = sc.nextInt();
		
		PerfectNumber pn = new PerfectNumber();
		Sum = pn.FindPerfectNumber(Number);
		
		if (Sum == Number) {
			System.out.format("%d is a Perfect Number", Number);
		}
		else {
			System.out.format("%d is NOT a Perfect Number", Number);
		}		
	}
}