public class ClassPelda {

    public static void main(String[] args) {
        Scanner input=new Scanner(System.in);
        Koord fo=new Koord();
        System.out.println("A fő pont koordinátái:");
        System.out.print("x=");
        fo.x=input.nextDouble();
        System.out.print("y=");
        fo.y=input.nextDouble();
        Koord masik=new Koord();
        do {
            System.out.println("A másik pont koordinátái:");
            System.out.print("x=");
            masik.x=input.nextDouble();
            System.out.print("y=");
            masik.y=input.nextDouble();
            System.out.println("A másik pont távolsága a főponttól: "+fo.tavEttol(masik));
            System.out.println("Az iranya pedig: "+fo.iranyEhhez(masik));
        } while (masik.x!=0||masik.y!=0);
    }   
}