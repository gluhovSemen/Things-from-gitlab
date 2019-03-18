/** 
 * @author Vasily Isaev
 * @version 7.20
*/
/*
Task_7_1

Прочитайте файл, содержащий код на языке Java. Определите, какие ключевые слова языка Java это код содержит. Выведите эти слова и их количество в другой файл. Используйте только байтовые потоки ввода-вывода.

Task_7_2

Прочитайте файл, содержащий код на языке Java. Определите, какие ключевые слова языка Java это код содержит. Выведите эти слова и их количество в другой файл. Используйте только символьные потоки ввода-вывода.*/
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;
public class Task_7_12 {
	// all the keyWords massive in Java
	final static String[] keyWords = { "abstract", "continue", "for", "new", "switch", "assert", "default", "goto",
			"package", "synchronized", "boolean", "do", "if", "private", "this", "break", "double", "implements",
			"protected", "throw", "byte", "else", "import", "public", "throws", "case", "enum", "instanceof", "return",
			"transient", "catch", "extends", "int", "short", "try", "char", "final", "interface", "static", "void",
			"class", "finally", "long", "strictfp", "volatile", "const", "float", "native", "super", "while" };

	// test if sub is substring of origin
	// can be optimizated with Knut-Morris algorithm
	public static boolean isSubstring(String origin, String sub) {
		for (int i = 0; i <= origin.length() - sub.length(); i++) {
			if (sub.charAt(0) == origin.charAt(i)) {
				for (int j = i; j < i + sub.length(); j++) {
					if (sub.charAt(j - i) != origin.charAt(j))
						break;
					if (j == i + sub.length() - 1)
						return true;
				}

			}
		}
		return false;
	}

	public static void main(String[] args) {
		// read by bytes in comments
		// try(FileOutputStream fos=new FileOutputStream("out.txt")){
		// try(FileInputStream fin=new
		// FileInputStream("/home/vasily/workspace/politekEx/src/text.txt")){
		// read by symbols
		try (FileWriter writer = new FileWriter("out.txt", false)) {
			writer.flush();
			try (Scanner reader = new Scanner("bin/code.txt"))// посимвольно
			{
				String strLine;
				
				String s ;
				int kwa = 0;// Key Words Amount
				while (reader.hasNext()) {
					s = reader.nextLine();
				//while ((c = (char) reader.read()) != null) {
				// while((c=fin.read())!=\n){
						for (int i = 0; i < keyWords.length; i++) {
							if (isSubstring(s, keyWords[i]))
								// byte[] buffer = keyWords.getBytes();
								// fos.write(buffer, 0, buffer.length);
								writer.write(keyWords[i] + "\n");
							kwa++;	
						}
						s = "";
					}
				
				writer.write(kwa);
				writer.flush();
		}
			} catch (IOException ex1) {

				System.out.println(ex1.getMessage());
			}
	}
	

}
