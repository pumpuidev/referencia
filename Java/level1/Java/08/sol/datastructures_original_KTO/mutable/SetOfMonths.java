package datastructures.mutable;
import datastructures.Month;
import static datastructures.Month.*;

public class SetOfMonths {

	private short bitmask;
	private SetOfMonths( short bitmask ){
		this.bitmask = bitmask;
	}

	public SetOfMonths add( Month month ){
		int position = month.ordinal();
		bitmask |= (1 << position);
		return this;
	}

	public boolean contains( Month month ){
		return (bitmask >> month.ordinal()) % 2 != 0;
	}

	public SetOfMonths remove( Month month ){
		int position = month.ordinal();
		int oneAtPosition = (1 << position);
		int zeroAtPosition = (-1) ^ oneAtPosition;
		bitmask &= zeroAtPosition;
		return this;
	}

	@Override public String toString(){
		StringBuilder sb = new StringBuilder("{");
		short s = bitmask;
		for( Month month: Month.values() ){
			if( s % 2 != 0 ){
				sb.append(month);
				sb.append(',');
			}
			s /= 2;
		}
		int len = sb.length();
		if( len > 1 ){
			sb.setCharAt(len-1,'}');
		} else {
			sb.append('}');
		}
		return sb.toString();
	}

	public static SetOfMonths empty(){
	       	return new SetOfMonths((short)0);
	}

	public static SetOfMonths of( Month... months ){
		short bitmask = 0;
		for( Month month: months ){
			int position = month.ordinal();
			bitmask |= (1 << position);
		}
		return new SetOfMonths(bitmask);
	}

	public static void main( String[] args ){
		System.out.println(empty().add(January).add(March).remove(March).add(June));
		System.out.println(empty());
		System.out.println(SetOfMonths.of(April, July, February).remove(July).remove(April).add(July));
	}


	/* Későbbi gyakorlatokon meg lehet majd írni ezeket is. */

	@Override public boolean equals( Object that ){
		return that != null && 
		       that.getClass().equals(getClass()) &&
		       ((SetOfMonths)that).bitmask == bitmask;
	}

	@Override public int hashCode(){ return bitmask; }

}
