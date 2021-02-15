class Sqrt {
	public static void main( String[] args ){

		double num = Double.parseDouble( System.console().readLine("Melyik számnak számoljuk ki a négyzetgyökét? ") );
		double epsilon = Double.parseDouble( System.console().readLine("Milyen pontossággal? ") );

		double current = 0.5 * num;
		double previous;
		do {
			previous = current;
			current = 0.5 * (previous + num /previous);
			System.out.println(previous);   // nyomkövetés 
		} while (Math.abs(current - previous) > epsilon);
		System.out.println("Négyzetgyök " + num + " közelítőleg: " + current);
	}
}
