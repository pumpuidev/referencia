package game;

import java.util.Arrays;
import java.util.Random;

public class Map{
	
	public static enum Field {
		EMPTY, ROCK_MONSTER, PAPER_MONSTER, SCISSORS_MONSTER, JOKER
	}
	
	private final Field[][] levels;
	private static final Random RANDOM = new Random();
	
	public Map(final int numberOfLevels, final int numberOfField){
		Field[] FieldValues = Field.values();
		int FieldSize = FieldValues.length;
		this.levels = new Field[numberOfLevels][numberOfField];
		for(int i = 0; i < numberOfLevels; i++){
			for(int j = 0; j < numberOfField; j++){
				this.levels[i][j] = FieldValues[RANDOM.nextInt(FieldSize)];
			}
		}
	}
	
	public Field[] getLevel(int n){
		return Arrays.copyOf(levels[n], levels[n].length);
	}
}