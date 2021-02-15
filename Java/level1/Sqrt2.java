class Sqrt2 {
	public static void main( String[] args ){
		double epsilon = args.length > 0 ? Double.parseDouble(args[0]) : 0.0000000001;
		double current = 0.5;
		double previous;
		do {
			previous = current;
			current = 1.0/(2.0 + previous);
			System.out.println(current);
		} while (Math.abs(current - previous) > epsilon);
		System.out.println("Négyzetgyök kettő közelítőleg: " + (1.0 + current));
	}
}
