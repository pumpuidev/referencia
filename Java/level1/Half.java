class Half {
    public static void main( String[] args ){
        int from, to;

        //System.out.print(  );
        from = Integer.parseInt( System.console().readLine("Kérem az alsó határt: "));
        //System.out.print(  );
        to   = Integer.parseInt( System.console().readLine("Kérem a felső határt: "));

        System.out.print( from + " és " + to + " között a számok fele:\n\n" );
        
        for( int idx = from; idx <= to; ++idx ){
            System.out.print( idx + " fele " + idx / 2.0 + "\n" );
        }
    }
}

