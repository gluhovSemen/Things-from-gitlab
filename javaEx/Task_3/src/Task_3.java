/** 
 * @author Vasily Isaev
 * @version 7.20
*/

/*Написать метод преобразования массива любого типа в ArrayList
  */

import java.util.ArrayList;
import java.util.List;

public class Task_3 {
	public static <T> List<T> toList(Object[] a) {
		ArrayList out = new ArrayList<Object>();
		for (Object o : a) // for any object of Array
			out.add(o); // add to ArrayList

		return out;
	}

	public static void arrListOut(ArrayList a) { // for print ArrayList
		for (int i = 0; i < a.size(); i++)
			System.out.print(a.get(i) + " ");
		System.out.println();
	}

	public static void main(String[] args) {
		ArrayList<?> tList = new ArrayList();

		// test for Integers
		Integer[] intArr = { 1, 2, 3 };

		tList = new ArrayList(toList(intArr));

		tList.remove(1);
		arrListOut(tList);
		// test for Doubles
		Double[] chArr = { 1.123, 2.123, 3.123 };

		tList = new ArrayList(toList(chArr));

		tList.remove(1);
		arrListOut(tList);
		// test for Strings
		String[] sArr = { " one ", " two ", " three " };

		tList = new ArrayList(toList(sArr));

		tList.remove(1);
		arrListOut(tList);
	}
}
