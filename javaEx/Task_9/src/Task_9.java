/** 
 * @author Vasily Isaev
 * @version 7.20
*/
/*
 Task_9
Создать “универсальный” класс, позволяющий получить значение из любого .properties-файла. 
Физическое чтение файла должно происходить только один раз. 
Учтите ситуацию, когда несколько потоков одновременно обращаются к одному и тому же файлу.
 */
import java.io.FileInputStream;
import java.io.IOException;
import java.util.Properties;

public class Task_9 {
	// Path to .properties file
	public static final String PATH_TO_PROPERTIES = "src/main/resources/config.properties";

	public static String TakeInfo() {

		FileInputStream fileInputStream;
		Properties prop = new Properties();

		try {
			// try to take info from fole
			fileInputStream = new FileInputStream(PATH_TO_PROPERTIES);
			prop.load(fileInputStream);

			String site = prop.getProperty("site");
			String loginToSite = prop.getProperty("login");
			String passwordToSite = prop.getProperty("password");

			// return taken data
			return ("site: " + site + "\nloginToSite: " + loginToSite + "\npasswordToSite: " + passwordToSite);

		} catch (IOException e) {
			System.out.println("Error: file " + PATH_TO_PROPERTIES + " not exist");
			e.printStackTrace();
			return "error";
		}

	}

}
