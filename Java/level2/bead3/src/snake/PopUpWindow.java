package snake; //jatek vege ablak

import javax.swing.JFrame;
import javax.swing.JOptionPane;

public class PopUpWindow {
    
    String name = "";
    
    PopUpWindow() {
        JFrame frame = new JFrame();        
        name = JOptionPane.showInputDialog(frame, "Name: ");
    }
    
    
    public String getName(){
        return name;
    }
}
