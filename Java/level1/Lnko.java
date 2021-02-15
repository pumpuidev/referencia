class Lnko {
	public static void main( String[] args ){
		if( args.length == 0 ){
			System.err.println("A parancssorban adja meg a számokat!");
		} else {
			long lnko = Long.parseLong(args[0]);
			for( int i=1; i<args.length; ++i ){
				long num = Long.parseLong(args[i]);
				while( num != 0 ){
					long tmp = lnko % num;
					lnko = num;
					num = tmp;
				}
			}
			System.out.println(lnko);
		}
	}
}
