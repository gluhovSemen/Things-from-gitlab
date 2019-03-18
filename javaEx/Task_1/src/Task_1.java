/** 
 * @author Vasily Isaev
 * @version 7.20
*/

/*
Task_1
Вывести на экран матрицу, рисующую крест из цифр.
Все остальные значения заполняются нулями. 
Размер матрицы пользователь вводит в консоли.
*/

import java.util.Random;
import java.util.Scanner;

public class Task_1 {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int size = scan.nextInt();
		Random rnd = new Random();
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				if (i == j || (i == size - j - 1)) {// find diagonal elements
					System.out.print(rnd.nextInt(8) + 1); // fill them with random numbers from 1 to 9
				} else {
					System.out.print(0);
				}
				System.out.print(" ");
			}
			System.out.println();
		}
		scan.close();
	}

}
