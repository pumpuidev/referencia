class Main{
	
	public static void main(String[] args){
		if(args.length == 2){
			BinaryCalculator.calculate(args[0], args[1]);
		}
		BinaryCalculator.calculate(5, 7);
		BinaryCalculator.calculate(5l, 7l);
		BinaryCalculator.calculate((short)5, (short)7);
		BinaryCalculator.calculate("5", "7");
		BinaryCalculator.calculate(5d, 7d);
		BinaryCalculator.calculate(5f, 7f);
	}
}