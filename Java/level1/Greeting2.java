class Greeting2 {
	public static void main( String[] args ){
		if (args.length != 1){
			System.err.println("Nem megfelelő számú parancssori argumentum.");
			System.exit(1);
		} else {
			System.out.println("Hello " + args[0] + "!");
		}	
	}
}
