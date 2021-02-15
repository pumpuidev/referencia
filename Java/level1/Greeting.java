class Greeting {
	public static void main( String[] args ){
		String name = System.console().readLine();
		System.console().printf("Hello %s!\n", name);
		// kiírás a standard outputra
		System.out.println("Hello " + name + "!");
		// stringek összefűzése
	}
}
