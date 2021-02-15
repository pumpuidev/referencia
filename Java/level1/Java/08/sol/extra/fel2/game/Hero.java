package game;

import static game.Map.Field.*;

public class Hero{
	
	private final String name;
	private int health;
	private int gold;
	private int resources;
	private final Map.Field losingField;
	private final Map.Field friendlyField;
	private final Map.Field winningField;
	private final Runnable jokerAction;
	
	/*
	private final Runnable healthAction = () -> this.heal();
	private final Runnable moneyAction = () -> this.addMoney();
	private final Runnable resourceAction = () -> this.addResources();
	*/
	private final Runnable healthAction = this::heal;
	private final Runnable moneyAction = this::addMoney;
	private final Runnable resourceAction = this::addResources;
	
	public Hero(String name, int health, int gold, int resources, Map.Field losingField, Map.Field friendlyField, Map.Field winningField, Runnable jokerAction){
		this.name = name;
		this.health = health;
		this.gold = gold;
		this.resources = resources;
		this.losingField = losingField;
		this.friendlyField = friendlyField;
		this.winningField = winningField;
		this.jokerAction = jokerAction;
	}
	
	public Hero(String name, int health, int gold, int resources, Map.Field losingField, Map.Field friendlyField, Map.Field winningField){
		this(name, health, gold, resources, losingField, friendlyField, winningField, () -> {});
	}
	
	public Hero(String name, int health, int gold, int resources, Map.Field losingField, Map.Field friendlyField, Map.Field winningField, Character joker){
		this.name = name;
		this.health = health;
		this.gold = gold;
		this.resources = resources;
		this.losingField = losingField;
		this.friendlyField = friendlyField;
		this.winningField = winningField;
		
		switch(joker) {
			case 'H':
				this.jokerAction = this.healthAction;
				break;
			case 'M':
				this.jokerAction = this.moneyAction;
				break;
			case 'R':
				this.jokerAction = this.resourceAction;
				break;
			default:
				this.jokerAction = () -> {};
		}
	}
	
	public String getName() { return this.name; }
	public int getHealth() { return this.health; }
	public int getGold() { return this.gold; }
	public int getResources() { return this.resources; }
	public Map.Field getLosingField() { return this.losingField; }
	public Map.Field getFriendlyField() { return this.friendlyField; }
	public Map.Field getWinningField() { return this.winningField; }
	
	public Character getJokerActionCharacter() {
		if(this.jokerAction.equals(this.healthAction)){
			return 'H';
		}
		if(this.jokerAction.equals(this.moneyAction)){
			return 'M';
		}
		if(this.jokerAction.equals(this.resourceAction)){
			return 'R';
		}
		return 'N';
	}
	
	public void processField(Map.Field actualField){
		if(actualField == this.losingField){
			this.health--;
		}
		if(actualField == this.friendlyField){
			this.addResources();
		}
		if(actualField == this.winningField){
			this.addMoney();
		}
		if(actualField == Map.Field.JOKER){
			this.jokerAction.run();
		}
	}
	
	
	private void heal() { this.health++; }
	private void addMoney() { this.gold++; }
	private void addResources() { this.resources++; }
	
	public String toString(){
		if(this.health <= 0)
			return this.name + " is dead.";
		return this.name + " has " +
			   this.health + " health and " +
			   this.gold + " golds and " +
			   this.resources + " resources.";
	}
	
}