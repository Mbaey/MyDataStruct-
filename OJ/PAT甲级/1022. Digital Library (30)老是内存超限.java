import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

class Book {
	String id;
	String title;
	String author;
	String Keywords;
	String publisher;	
	String year;
	public Book(String id, String title, String author, String keywords, String publisher, String year) {
		super();
		this.id = id;
		this.title = title;
		this.author = author;
		Keywords = keywords;
		this.publisher = publisher;
		this.year = year;
	}
	public Book() {
		super();
	}
	@Override
	public String toString() {
		return "Book [id=" + id + ", title=" + title + ", author=" + author + ", Keywords=" + Keywords + ", publisher="
				+ publisher + ", year=" + year + "]";
	}
		
}

public class Main {

	public static void main(String[] args) throws FileNotFoundException {
		Scanner s = new Scanner(new FileInputStream(new File("1.txt")));
//		Scanner s = new Scanner(System.in);
		int N = s.nextInt();
		String str = s.nextLine();//case \n
		ArrayList<Book> books = new ArrayList<Book>();
		for (int i = 0; i < N; i++) {
			read(s, books);
		}
		
		int M = s.nextInt();
		str = s.nextLine();//case \n
		Collections.sort(books,new Comparator<Book>() {

			@Override
			public int compare(Book o1, Book o2) {
				return o1.id.compareTo(o2.id);
			}
		});
		for (int i = 0; i < M; i++) {
//			1: a book title
//			2: name of an author
//			3: a key word
//			4: name of a publisher
//			5: a 4-digit number representing the year
			check(s, N, books);
		}
		s.close();
	}

	private static void check(Scanner s, int N, ArrayList<Book> books) {
		String key =  s.nextLine();
		System.out.println(key);
		int id = key.charAt(0) - '0';
		key = key.substring(3);
		
		boolean flag= true;
		switch (id) {
		case 1:
			for (int j = 0; j < N; j++) {
				Book book = books.get(j);
				if(book.title.equals(key)){
					flag = false;
					System.out.println(book.id);
				}
			}
			break;
		case 2:
			for (int j = 0; j < N; j++) {
				Book book = books.get(j);
				if(book.author.equals(key)){flag = false;
					System.out.println(book.id);
				}
			}
			break;
		case 3:
			for (int j = 0; j < N; j++) {
				Book book = books.get(j);
				if(book.Keywords.contains(key)){flag = false;
					System.out.println(book.id);
				}
			}
			break;
		case 4:
			for (int j = 0; j < N; j++) {
				Book book = books.get(j);
				if(book.publisher.equals(key)){flag = false;
					System.out.println(book.id);
				}
			}
			break;
		case 5:
			for (int j = 0; j < N; j++) {
				Book book = books.get(j);
				if(book.year.equals(key)){flag = false;
					System.out.println(book.id);
				}
			}
			break;

		default:
			break;
		}
		if(flag){
			System.out.println("Not Found");
		}
	}

	private static void read(Scanner s, ArrayList<Book> books) {
		String id = s.nextLine();
		String title = s.nextLine();
		String author= s.nextLine();
		String keywords= s.nextLine();
		String publisher= s.nextLine();
		String year=s.nextLine();
		Book book = new Book(id, title, author, keywords, publisher, year);
//		System.out.println(book);
		books.add(book);
	}

}
