import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

/**
 * This class will check if the button is pressed, and if it is
 * pressed it will switch the panel in model and display the new
 * display. 
 * @author Marcus Lorenzana
 *
 */

public class PanelSwitcherController implements ActionListener {

	private PanelSwitcherModel model;
	private PanelSwitcherView view;
	

	public PanelSwitcherController(PanelSwitcherView view, PanelSwitcherModel model ) {
		this.model = model;
		this.view = view;
	}
	

	public void actionPerformed(ActionEvent e) {
		System.out.println(e.getActionCommand());
		System.out.println("button pressed"); 
		model.switchPanel(); 
		view.displayPanel(model.whichPanel());
	}
}
