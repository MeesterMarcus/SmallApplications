package calculator;

import javax.swing.JFrame;
import javax.swing.UIManager;
import javax.swing.UIManager.LookAndFeelInfo;

/**
 * The Calculator class along with CalculatorController,
 * CalculatorModel and CalculatorView implements a 
 * simple-minded calculator.
 * The implementation is based on the MVC design pattern.
 * 
 * @author Tom Bylander
 */
public class Calculator {
	/**
	 * Create the model, view and controller objects,
	 * and launch the application.
	 */
	public static void main(String[] args) {
		/* create new model, view and controller */
		try {
		    for (LookAndFeelInfo info : UIManager.getInstalledLookAndFeels()) {
		        if ("Nimbus".equals(info.getName())) {
		            UIManager.setLookAndFeel(info.getClassName());
		            break;
		        }
		    }
		} catch (Exception e) {
		    // If Nimbus is not available, you can set the GUI to another look and feel.
		}
		
		CalculatorModel model = new CalculatorModel();
		CalculatorView view = new CalculatorView();
		CalculatorController controller = new CalculatorController(model, view);
		
		/* register controller as listener */
		view.registerListener(controller);
		
		/* start it up */
		view.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		view.setSize(480, 300);
		view.setVisible(true);
	}
}
