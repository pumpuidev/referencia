class BinaryCalculator{
	
	public static void calculate(int a, int b){
		System.out.println("INTEGERS***");
		doCalculate(a, b);
	}
	
	public static void calculate(long a, long b){
		System.out.println("LONGS***");
		doCalculate(a, b);
	}
	
	public static void calculate(short a, short b){
		System.out.println("SHORTS***");
		doCalculate(a, b);
	}
	
	public static void calculate(String a, String b){
		System.out.println("STRINGS***");
		calculate(Double.parseDouble(a), Double.parseDouble(b));
	}
	
	public static void calculate(double a, double b){
		System.out.println("DOUBLES***");
		doCalculate((long)a, (long)b);
	}
	
	public static void calculate(float a, float b){
		System.out.println("FLOATS***");
		doCalculate((long)a, (long)b);
	}
	
	private static void doCalculate(long a, long b){
		System.out.println("A number: " + Long.toBinaryString(a));
		System.out.println("B number: " + Long.toBinaryString(b));
		System.out.println("A AND B: " + Long.toBinaryString(a & b));
		System.out.println("A OR B: " + Long.toBinaryString(a | b));
		System.out.println("A XOR B: " + Long.toBinaryString(a ^ b));
		System.out.println("NOT A: " + Long.toBinaryString(~a));
		System.out.println("NOT B: " + Long.toBinaryString(~b));
		
	}
}