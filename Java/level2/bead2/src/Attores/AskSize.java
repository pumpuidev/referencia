package Attores;

import java.awt.event.ActionEvent;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import javax.swing.JMenuBar;
import javax.swing.JButton;
import javax.swing.JPanel;
import javax.swing.JMenu;
import javax.swing.AbstractAction;
import javax.swing.JFrame;
import javax.swing.JOptionPane;

public class AskSize extends JFrame {
    JPanel p = new JPanel();
    JMenuBar bar = new JMenuBar();
    JMenu menu = new JMenu();
    JButton six;
    JButton eight;
    JButton ten;
    
    public AskSize() {
        super("Size");
        setDefaultCloseOperation(DO_NOTHING_ON_CLOSE);
        addWindowListener(new WindowAdapter() {

            @Override
            public void windowClosing(WindowEvent e) {
                showExitConfirmation();
            }

        });
        setResizable(false);
        
        six = new JButton(new AbstractAction() {
            @Override
            public void actionPerformed(ActionEvent e) {
                new Window((byte) 6);
                doUponExit();
            }
        });
        six.setText("6x6");
        
        eight = new JButton(new AbstractAction() {
            @Override
            public void actionPerformed(ActionEvent e) {
                new Window((byte) 8);
                doUponExit();
            }
        });
        eight.setText("8x8");
        
        ten = new JButton(new AbstractAction() {
            @Override
            public void actionPerformed(ActionEvent e) {
                new Window((byte) 10);
                doUponExit();
            }
        });
        ten.setText("10x10");
        
        p.add(six);
        p.add(eight);
        p.add(ten);
        add(p);
        pack();
        setVisible(true);
    }
    
    protected void showExitConfirmation() {
        int n = JOptionPane.showConfirmDialog(this, "Are you sure?",
            "Exit", JOptionPane.YES_NO_OPTION);
        if (n == JOptionPane.YES_OPTION) {
            doUponExit();
        }
    }
    
    private void doUponExit() {
        this.dispose();
    }
}

