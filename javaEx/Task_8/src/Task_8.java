/** 
 * @author Vasily Isaev
 * @version 7.20
*/
/*Task_8
Разработать приложение, позволяющее просматривать файлы и каталоги файловой системы, а также создавать и удалять текстовые файлы. Для работы с текстовыми файлами необходимо реализовать функциональность записи (дозаписи) в файл. 
Требуется определить исключения для каждого слоя приложения и корректно их обработать.
*/
import java.awt.Dimension;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.File;
 
import javax.swing.Box;
import javax.swing.BoxLayout;
import javax.swing.JButton;
import javax.swing.JDialog;
import javax.swing.JFileChooser;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
 
public class Task_8 extends JFrame {
 
    public Task_8() {
        super("Text window");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
 
        JPanel panel = new JPanel();
        panel.setLayout(new BoxLayout(panel, BoxLayout.Y_AXIS));
         
        panel.add(Box.createVerticalGlue());
 
        final JLabel label = new JLabel("Choose File");
        label.setAlignmentX(CENTER_ALIGNMENT);
        panel.add(label);
 
        panel.add(Box.createRigidArea(new Dimension(10, 10)));
 
        JButton button = new JButton("Start");
        button.setAlignmentX(CENTER_ALIGNMENT);
 
        button.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                JFileChooser fileopen = new JFileChooser();             
                int ret = fileopen.showDialog(null, "Open file");                
                if (ret == JFileChooser.APPROVE_OPTION) {
                    File file = fileopen.getSelectedFile();
                    label.setText(file.getName());
                }
            }
        });
 
        panel.add(button);
        panel.add(Box.createVerticalGlue());
        getContentPane().add(panel);
 
        setPreferredSize(new Dimension(600, 600));
        pack();
        setLocationRelativeTo(null);
        setVisible(true);
    }
 
    public static void main(String[] args) {
        javax.swing.SwingUtilities.invokeLater(new Runnable() {
            public void run() {
                JFrame.setDefaultLookAndFeelDecorated(true);
                JDialog.setDefaultLookAndFeelDecorated(true);
                new Task_8();
            }
        });
    }
}
