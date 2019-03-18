/** 
 * @author Vasily Isaev
 * @version 7.20
*/

/*
 Base
  Работа с БД. 
  Сформировать таблицу товаров (id, prodid, title, cost) запросом из Java-приложения. 
  При запуске приложения очищать таблицу и заполнять N товаров вида: id_товара 1 товар1 10 
  Написать консольное приложение, которое позволяет узнать цену товара по его имени, 
  либо если такого товара нет, то должно быть выведено сообщение "Такого товара нет". 
  Пример: /price товар777
 */

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Scanner;

public class Base {
	class Product {
		int index;
		String name;
		int price;

		Product(int index_, String name_, int price_) {
			index = index_;
			name = name_;
			price = price_;
		}

		String fromPrtoStr(Product p) {
			return p.index + " " + p.name + " " + p.price;
		}

	}

	public static int indexFromStr(String str) {
		int i = 0;
		while (str.charAt(i) != ' ') {
			i++;
		}
		try {
			return Integer.valueOf(str.substring(0, i));
		} catch (NumberFormatException e) {
			System.out.println("Некорректная запись в базе данных");
			return 0;
		}
	}

	public static String nameFromStr(String str) {
		int i = 0;
		while (str.charAt(i) != ' ') {
			i++;
		}
		int start = i + 1;
		do {
			i++;
		} while (str.charAt(i) != ' ');
		return str.substring(start, i);
	}

	public static int priceFromStr(String str) {
		int i = 0;
		int k = 0;
		while (k != 2) {
			i++;
			if (str.charAt(i) == ' ')
				k++;
		}

		try {
			return Integer.valueOf(str.substring(i + 1));
		} catch (NumberFormatException e) {
			System.out.println("Некорректная запись в базе данных");
			return 0;
		}
	}

	static final String[] defProduct = { "1 кресло 3000", "2 шкаф 7000", "3 диван 11000", "4 кровать 9000" };

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

	static int price(String input) throws IOException {

		int i = 0;
		while (input.charAt(i) != ' ') {
			i++;
		}
		String name = input.substring(i + 1, input.length());
		FileInputStream fstream = new FileInputStream("Base.data");
		BufferedReader br = new BufferedReader(new InputStreamReader(fstream));
		String strLine;
		while ((strLine = br.readLine()) != null) {
			if (isSubstring(strLine, name)) {
				return Integer.valueOf(priceFromStr(strLine));
			}

		}
		System.out.println("Товар " + name + " отсутствует в базе данных");
		return 0;
	}

	static int index(String input) throws IOException {

		int i = 0;
		while (input.charAt(i) != ' ') {
			i++;
		}
		String name = input.substring(i + 1, input.length());
		FileInputStream fstream = new FileInputStream("Base.data");
		BufferedReader br = new BufferedReader(new InputStreamReader(fstream));
		String strLine;
		while ((strLine = br.readLine()) != null) {
			if (isSubstring(strLine, name)) {
				return Integer.valueOf(indexFromStr(strLine));
			}

		}
		System.out.println("Товар " + name + " отсутствует в базе данных");
		return 0;
	}

	static int getIndex(String name) throws IOException {
		FileInputStream fstream = new FileInputStream("Base.data");
		BufferedReader br = new BufferedReader(new InputStreamReader(fstream));
		String strLine;
		String ind = "";
		while ((strLine = br.readLine()) != null) {
			if (isSubstring(strLine, name)) {

				for (int i = 0; i < strLine.length(); i++) {
					if (strLine.charAt(i) == ' ') {
						break;
					}
					ind += strLine.charAt(i);
				}
			}
		}
		return Integer.valueOf(ind);
	}

	static String priceByName(String productName) {
		try {
			FileInputStream fstream = new FileInputStream("Base.data");
			BufferedReader br = new BufferedReader(new InputStreamReader(fstream));
			String strLine;
			while ((strLine = br.readLine()) != null) {
				if (isSubstring(strLine, productName)) {
					String s = "" + priceFromStr(strLine);
					return s;
				}
			}
		} catch (IOException e) {
			System.out.println("Ошибка");
		}
		return "can't fund " + productName + " in our Base";
	}

	static String changePrice(String input) {
		String name = "";
		String price = "";
		for (int i = "изменить ".length(); i < input.length(); i++) {
			if (input.charAt(i) == ' ') {
				price = input.substring(i + 1, input.length());
				break;
			}
			name += input.charAt(i);
		}

		try {
			FileInputStream fstream = new FileInputStream("Base.data");
			BufferedReader br = new BufferedReader(new InputStreamReader(fstream));
			String strLine;
			StringBuilder sb = new StringBuilder();
			while ((strLine = br.readLine()) != null) {

				sb.append(strLine.replace(getIndex(name) + " " + name + " " + priceByName(name),
						getIndex(name) + " " + name + " " + price)).append("\r\n");
			}
			try (FileWriter fileWriter = new FileWriter("Base.data")) {
				fileWriter.write(sb.toString());
			}
		} catch (IOException e) {

			System.out.println("Ошибка");

		}
		return "теперь цена товара \"" + name + "\" - " + price;

	}

	static ArrayList priceRange(String input) throws IOException {
		ArrayList<String> out = new ArrayList<String>();
		String price1 = "";
		String price2 = "";
		for (int i = "Диапазон ".length(); i < input.length(); i++) {
			if (input.charAt(i) == ' ')
				break;
			price1 += input.charAt(i);
		}
		price2 = input.substring("Диапазон ".length() + price1.length() + 1, input.length());
		FileInputStream fstream = new FileInputStream("Base.data");
		BufferedReader br = new BufferedReader(new InputStreamReader(fstream));
		String strLine;
		while ((strLine = br.readLine()) != null) {
			if (priceFromStr(strLine) > Integer.valueOf(price1) && priceFromStr(strLine) < Integer.valueOf(price2)) {
				out.add(strLine);
			}
		}
		return out;
	}

	public static void main(String[] args) throws IOException {
		Scanner scan = new Scanner(System.in);
		FileWriter writer = new FileWriter("Base.data", false);

		for (int i = 0; i < defProduct.length; i++) {
			writer.write(defProduct[i] + "\n");
		}
		writer.flush();
		for (int i = 0; i < defProduct.length; i++) {
			System.out.println(priceByName(nameFromStr(defProduct[i])));
		}
		String input = "";
		System.out.println("Это база данных магазина мебели \n" + "Доступные комманды :\n");
		System.out.println("цена имя_товара - узнать цену товара ");
		System.out.println("изменить имя_товара новая_цена - изменить цену  ");
		System.out.println("индекс имя_товара - узнать идекс товара");
		System.out.println("диапазон цена1 цена2 - вывести товары в ценовом диапозоне");
		System.out.println("все - вывести все товары в базе данных");
		System.out.println("выход - выход ");

		while (!input.equals("выход") && !input.equals("Выход")) {
			input = scan.nextLine();
			if (isSubstring(input, "цена ")) {
				System.out.println(price(input));
			} else if (isSubstring(input, "индекс ")) {
				System.out.println(index(input));
			} else if (isSubstring(input, "изменить ")) {
				System.out.println(changePrice(input));
			} else if (isSubstring(input, "диапазон ")) {
				for(int i = 0; i < priceRange(input).size(); i ++) {
					System.out.println(priceRange(input).get(i));
				}
			} else if (isSubstring(input, "помощь")) {
				System.out.println("Это база данных магазина мебели \n" + "Доступные комманды :\n");
				System.out.println("цена имя_товара - узнать цену товара ");
				System.out.println("изменить имя_товара новая_цена - изменить цену  ");
				System.out.println("индекс имя_товара - узнать идекс товара");
				System.out.println("диапазон цена1 цена2 - вывести товары в ценовом диапозоне");
				System.out.println("выход - выход ");
			} else if (isSubstring(input, "все")) {
				for(int i = 0; i < priceRange("диапазон 0 100000").size(); i ++) {
					System.out.println(priceRange("диапазон 0 100000").get(i));
				}
			} 
			else {
				System.out.println("Такой команды не существует. \nкоманда \"помощь\" выведет доступные команды");
			}
		}

	}

}
