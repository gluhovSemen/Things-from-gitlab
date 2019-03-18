
/** 
 * @author Vasily Isaev
 * @version 7.20
*/
/*
Task_2

Спроектировать и разработать классы «Запись в блокноте» и «Блокнот» 
(записи блокнота хранятся в массиве)
Реализовать методы: 
1. Добавить запись 
2. Удалить запись 
3. Редактировать запись 
4. Посмотреть все записи 	
*/

import java.util.ArrayList;
import java.util.Scanner;

class NotePadNote {
	Scanner scan = new Scanner(System.in);
	private String mainInfo;
	// constructor
	NotePadNote(String text) { 
		mainInfo = text;
	}
	// shows note and swap it with user's input
	void noteEdit() { 
		System.out.println('\"' + mainInfo + '\"' + " - it is note now. \nEnter your text to swap with this note.");
		mainInfo = scan.nextLine();
	}
	// to get access to private field
	String showInf() { 
		return mainInfo;
	}
}

class NotePad {
	Scanner scan = new Scanner(System.in);
	ArrayList<NotePadNote> notes = new ArrayList<NotePadNote>();
	// show all notes after every method of this class
	void showNotes() {
		System.out.println("*****NOW IN NOTEPAD*****");
		for (int i = 0; i < notes.size(); i++) {
			System.out.print("note " + i + " : ");
			System.out.println(notes.get(i).showInf());
		}
		System.out.println("******NOTES END*********");
	}

	// add note to place 'place' , if place is out of range - add to the end
	void noteAdd() {
		System.out.println("enter format: \nnumber_of_place note_text \nexample:\n1 test");
		int place = scan.nextInt();
		if (place > notes.size())
			place = notes.size();
		NotePadNote inputNote = new NotePadNote(scan.nextLine());
		notes.add(place, inputNote);
		showNotes();
	}

	void noteDelete() {
		showNotes();
		System.out.println("enter number of note to delete this");
		int place = scan.nextInt();
		try {
			notes.remove(place);
			showNotes();
		} catch (IndexOutOfBoundsException e) {
			System.out.println(e.getMessage());
		}
	}

	// edit note number 'place' to note from console
	void noteEdit() {
		System.out.println("enter number of note you want to edit");
		int place = scan.nextInt();
		notes.get(place).noteEdit();
		showNotes();
	}
}

public class Task_2 {

	public static void main(String[] args) {
		// some simple tests
		NotePad notePad = new NotePad();
		notePad.noteAdd();
		notePad.noteAdd();
		notePad.noteAdd();
		notePad.noteDelete();
		notePad.noteAdd();
		notePad.noteEdit();
		notePad.showNotes();
	}
}

