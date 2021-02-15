class E {

	static double chain( int depth, int n ){
		return depth <= 0 ? 1.0
			           : (1.0 + 1.0/(1.0 + 1.0 / (n + 1.0/chain(depth-3,n+2))));
	}

	public static void main( String[] args ){
		int depth = args.length > 0 ? Integer.parseInt(args[0]) : 20;
		double result =  1.0 + chain(depth,2);
		System.out.println("e közelítőleg: " + result);
	}
}
