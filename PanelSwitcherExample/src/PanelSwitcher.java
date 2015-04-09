import javax.swing.*;

/**
 * Main class that will create the model, view, and controller.
 * It will then register the view to the controller and performs
 * panel switching on button press. 
 * 
 * @author Tom Bylander
 * @author Marcus Lorenzana
 */
public class PanelSwitcher {

    public static void main(String[] args) {
        PanelSwitcherModel model = new PanelSwitcherModel();
        PanelSwitcherView view = new PanelSwitcherView();
	    PanelSwitcherController controller = new PanelSwitcherController(view, model);
        
        view.register(controller);

        view.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        view.setSize(400,300);
        view.setVisible(true);
    }

}
