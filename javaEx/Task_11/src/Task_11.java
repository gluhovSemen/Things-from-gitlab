/** 
 * @author Vasily Isaev
 * @version 7.20
*/
/*
Task_11

Добавьте GUI для приложения из Task_10.
*/

import java.awt.Container;
import java.awt.Dimension;
import java.awt.Font;
import java.awt.GridLayout;
import java.awt.HeadlessException;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.FileWriter;
import java.io.IOException;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JTextField;
import javax.swing.UIManager;
public class Task_11 extends JFrame {
	final String info = "<html>Это база данных магазина мебели<br>Доступные комманды :"
			+ "<br>цена имя_товара - узнать цену товара<br>изменить имя_товара новая_цена - изменить цену"
			+ "<br>индекс имя_товара - узнать идекс товара"
			+ "<br>диапазон цена1 цена2 - вывести товары в ценовом диапозоне<html>";
	private static final long serialVersionUID = 1L;
	JButton button = new JButton("выполнить");
	private static JTextField input1 = new JTextField("", 5);

	private JLabel label = new JLabel(info);

	public Task_11() {
		label.setFont(new Font("Serif", Font.PLAIN, 40));
		button.setFont(new Font("Serif", Font.PLAIN, 40));
		input1.setFont(new Font("Serif", Font.PLAIN, 40));
		Font font = new Font(Font.SANS_SERIF, Font.PLAIN, 40);
		UIManager.put("OptionPane.messageFont", font);
		UIManager.put("OptionPane.buttonFont", font);
		UIManager.put("OptionPane.minimumSize", new Dimension(500, 300));
		this.setBounds(600, 600, 1750, 1700);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		Container container = this.getContentPane();
		container.setLayout(new GridLayout(3, 10, 10, 20));
		container.add(label);
		container.add(input1);
		button.addActionListener(new ButtonEventListener());
		container.add(button);
	}

	class ButtonEventListener implements ActionListener {
		public void actionPerformed(ActionEvent e) {

			if (Base.isSubstring(input1.getText(), "цена ")) {
				try {
					JOptionPane.showMessageDialog(null, (Base.price(input1.getText())), "Цена",
							JOptionPane.PLAIN_MESSAGE);
					input1.setText("");
				} catch (HeadlessException | IOException e1) {
					e1.printStackTrace();
				}
			}
			if (Base.isSubstring(input1.getText(), "индекс ")) {
				try {
					JOptionPane.showMessageDialog(null, (Base.index(input1.getText())), "Информация",
							JOptionPane.PLAIN_MESSAGE);
					input1.setText("");
				} catch (HeadlessException | IOException e1) {
					e1.printStackTrace();
				}
			}
			if (Base.isSubstring(input1.getText(), "все")) {
			
				try {
					String str = "";
					for (int i = 0; i < Base.priceRange("диапазон 0 100000").size(); i++) {
						str += Base.priceRange("диапазон 0 100000").get(i) + "\n";
					}
					JOptionPane.showMessageDialog(null, str, "Список товаров", JOptionPane.PLAIN_MESSAGE);
					input1.setText("");
				} catch (HeadlessException | IOException e1) {
					e1.printStackTrace();
				}
				while(true) {}
			}
			if (Base.isSubstring(input1.getText(), "диапазон")) {
				try {
					String str = "";
					for (int i = 0; i < Base.priceRange(input1.getText()).size(); i++) {
						str += Base.priceRange(input1.getText()).get(i) + "\n";
					}
					JOptionPane.showMessageDialog(null, str, "Список товаров", JOptionPane.PLAIN_MESSAGE);
					input1.setText("");
				} catch (HeadlessException | IOException e1) {
					e1.printStackTrace();
				}
			}

			if (Base.isSubstring(input1.getText(), "помощь")) {

				JOptionPane.showMessageDialog(null, (info), "Цена", JOptionPane.PLAIN_MESSAGE);
			}

		}
	}

	public static void main(String[] args) throws IOException {

		@SuppressWarnings("resource")
		FileWriter writer = new FileWriter("base.data", false);

		for (int i = 0; i < Base.defProduct.length; i++) {
			writer.write(Base.defProduct[i] + "\n");
		}
		writer.flush();
		Task_11 app = new Task_11();

		app.setVisible(true);

	}
}
