package game;

import static game.Map.Field.*;

import java.io.IOException;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.Arrays;
import java.util.Scanner; 

public class Main{
	
	static int levelsNumber, fieldsNumber;
	static Hero[] heroes;
	static Scanner scan = new Scanner(System.in);

	public static void main(String[] args){
		if( args.length == 1){
			loadFromFile(args[0]);
			System.out.println("Heroes read from binary file: ");
			Arrays.stream(heroes)
				  .map(Hero::toString)
				  .forEach(System.out::println);
		} else {
			levelsNumber = 5;
			fieldsNumber = 40;
			heroes = new Hero[3];
			heroes[0] = new Hero("RockHero", 10, 40, 40, PAPER_MONSTER, ROCK_MONSTER, SCISSORS_MONSTER, 'H');
			heroes[1] = new Hero("ScissorsHero", 40, 10, 40, ROCK_MONSTER, SCISSORS_MONSTER, PAPER_MONSTER, 'M');
			heroes[2] = new Hero("PaperHero", 40, 40, 10, SCISSORS_MONSTER, PAPER_MONSTER, ROCK_MONSTER, 'R');
		}
		Map map = new Map(levelsNumber,fieldsNumber);
		
		for(int i = 0; i < levelsNumber; ++i){
			System.out.println("--- " + (i+1) + ". ROUND ---");
			for(Map.Field field : map.getLevel(i)){
				
				Arrays.stream(heroes)
					  .filter(h -> h.getHealth() >= 0)
					  .forEach(h -> h.processField(field));
			}
			Arrays.stream(heroes)
				  .map(Hero::toString)
				  .forEach(System.out::println);
			if(i < levelsNumber-1){
				System.out.println("Do you want to save it or keep going? Type S to save, anything else to keep going!");
				if(scan.next().equals("S")){
					System.out.println("Please add a filename.");
					saveToFile(scan.next());
					System.exit(0);
				}
			}
		}
		
	}
	
	public static void loadFromFile(String fileName){
		try (ObjectInputStream in = new ObjectInputStream(new FileInputStream(fileName))) {
			
			levelsNumber = in.readInt();
			fieldsNumber = in.readInt();
			int heroesNumber = in.readInt();
			heroes = new Hero[heroesNumber];
			for (int i = 0; i < heroesNumber; i++) {
				heroes[i] = new Hero(in.readUTF(), in.readInt(), in.readInt(), in.readInt(), Map.Field.valueOf(in.readUTF()),
									Map.Field.valueOf(in.readUTF()), Map.Field.valueOf(in.readUTF()), in.readUTF().charAt(0));
			}
		} catch (IOException e){
			System.out.println("Error during reading from file.");
		}
	}
	
	public static void saveToFile(String fileName){
		try (ObjectOutputStream out = new ObjectOutputStream(new FileOutputStream(fileName))) {
			
			out.writeInt(levelsNumber);
			out.writeInt(fieldsNumber);
			out.writeInt(heroes.length);
			for (int i = 0; i < heroes.length; i++) {
				out.writeUTF(heroes[i].getName());
				out.writeInt(heroes[i].getHealth());
				out.writeInt(heroes[i].getGold());
				out.writeInt(heroes[i].getResources());
				out.writeUTF(heroes[i].getLosingField().toString());
				out.writeUTF(heroes[i].getFriendlyField().toString());
				out.writeUTF(heroes[i].getWinningField().toString());
				out.writeUTF(heroes[i].getJokerActionCharacter().toString());
			}
		} catch (IOException e){
			System.out.println("Error during saving to file.");
		}
	}
}