package Attores;

import java.awt.BorderLayout;
import java.awt.event.ActionEvent;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import javax.swing.AbstractAction;
import javax.swing.JButton;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JFrame;
import javax.swing.JLabel;
import static javax.swing.WindowConstants.DO_NOTHING_ON_CLOSE;

public class GameOver extends JFrame {
    JPanel p = new JPanel();
    JMenuBar bar = new JMenuBar();
    JMenu menu = new JMenu();
    JLabel label;
    JButton newGame;
    JButton exit;
    
    public GameOver(boolean whiteWins) {
        super("Game Over");
        setDefaultCloseOperation(DO_NOTHING_ON_CLOSE);
        if (whiteWins) label = new JLabel("White Wins!");
        else label = new JLabel("Black Wins!");
        
        addWindowListener(new WindowAdapter() {

            @Override
            public void windowClosing(WindowEvent e) {
                showExitConfirmation();
            }

        });
        setResizable(false);
        
        newGame = new JButton(new AbstractAction() {
            @Override
            public void actionPerformed(ActionEvent e) {
                new AskSize();
                doUponExit();
            }
        });
        newGame.setText("New Game");
        
        exit = new JButton(new AbstractAction() {
            @Override
            public void actionPerformed(ActionEvent e) {
                showExitConfirmation();
            }
        });
        exit.setText("Exit");
        
        p.add(label);
        p.add(newGame);
        p.add(exit);
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
