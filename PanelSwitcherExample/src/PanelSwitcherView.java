import java.awt.*;
import java.awt.event.*;

import javax.swing.*;

/**
 * Creates the view for the two panels, and can register button
 * to the PanelSwitcherController. When button is pressed, will switch to
 * the other panel. 
 * 
 * @author Tom Bylander
 * @author Marcus Lorenzana
 */
public class PanelSwitcherView extends JFrame {
    private JPanel panel1, panel2;
    private JButton button;
    private Font font; 

    public PanelSwitcherView() {
        super("Panel Switching Test");

        font = new Font("SansSerif", Font.BOLD, 30);
        panel1 = new JPanel();
        panel1.setLayout(new GridLayout(2, 2, 5, 5));

        JLabel label = new JLabel("four", JLabel.CENTER);
        label.setBackground(Color.MAGENTA);
        label.setFont(font);
        label.setOpaque(true);
        panel1.add(label);

        label = new JLabel("JLabels", JLabel.CENTER);
        label.setBackground(Color.BLUE);
        label.setFont(font);
        label.setOpaque(true);
        panel1.add(label);

        label = new JLabel("are", JLabel.CENTER);
        panel1.add(label);
        label.setBackground(Color.CYAN);
        label.setFont(font);
        label.setOpaque(true);

        label = new JLabel("shown", JLabel.CENTER);
        panel1.add(label);
        label.setBackground(Color.GREEN);
        label.setFont(font);
        label.setOpaque(true);

        font = new Font("Serif", Font.ITALIC, 30);
        panel2 = new JPanel();
        panel2.setLayout(new BorderLayout());

        label = new JLabel("five", JLabel.CENTER);
        label.setBackground(Color.GREEN);
        label.setFont(font);
        label.setOpaque(true);
        panel2.add(label, BorderLayout.NORTH);

        label = new JLabel("JLabels", JLabel.CENTER);
        label.setBackground(Color.YELLOW);
        label.setFont(font);
        label.setOpaque(true);
        panel2.add(label, BorderLayout.WEST);

        label = new JLabel("for", JLabel.CENTER);
        label.setBackground(Color.ORANGE);
        label.setFont(font);
        label.setOpaque(true);
        panel2.add(label, BorderLayout.CENTER);

        label = new JLabel("this", JLabel.CENTER);
        label.setBackground(Color.PINK);
        label.setFont(font);
        label.setOpaque(true);
        panel2.add(label, BorderLayout.EAST);

        label = new JLabel("panel", JLabel.CENTER);
        label.setBackground(Color.RED);
        label.setFont(font);
        label.setOpaque(true);
        panel2.add(label, BorderLayout.SOUTH);

        font = new Font("Monospaced", Font.BOLD + Font.ITALIC, 30);
        button = new JButton("Switch Panels");
        button.setFont(font);
        add(button, BorderLayout.NORTH);

        add(panel1, BorderLayout.CENTER);
    }
    
    /**
     * Register the button to the controller
     * @param controller
     */
    public void register(PanelSwitcherController controller) {
		button.addActionListener(controller);
	}
	

    /**
     * This seems to be a way to switch JPanels.  Let me know of any bugs
     * or more elegant ways of doing the same task.
     * 
     * @param whichPanel Should panel1 or panel2 be displayed?
     */
    public void displayPanel(int whichPanel) {
        remove(panel1); // doesn't seem to mind trying to remove
        remove(panel2); // components that are not displayed
        if (whichPanel == 1) {
            System.out.println("Should display panel1");
            add(panel1, BorderLayout.CENTER);
        } else {
            System.out.println("Should display panel2");
            add(panel2, BorderLayout.CENTER);
        }
        validate();
        repaint();
    }
}
