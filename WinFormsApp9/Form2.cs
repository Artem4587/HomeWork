using System;
using System.Collections.Generic;
using System.Linq;

class Book
{
    public string Title { get; set; }
    public string Author { get; set; }
    public int Year { get; set; }
    public int Id { get; set; } 

    // Конструктор для удобного создания объектов Book
    public Book(string title, string author, int year, int id)
    {
        Title = title;
        Author = author;
        Year = year;
        Id = id;
    }
    public override string ToString()
    {
        return $"Id: {Id}, Title: {Title}, Author: {Author}, Year: {Year}";
    }
}

class Library
{
    private Dictionary<int, Book> books = new Dictionary<int, Book>();

    //Метод для добавления книги в библиотеку
    public void AddBook(Book book)
    {
        if (books.ContainsKey(book.Id))
        {
            Console.WriteLine($"Книга с ID {book.Id} уже существует в библиотеке.");
        }
        else
        {
            books.Add(book.Id, book);
            Console.WriteLine($"Книга '{book.Title}' добавлена в библиотеку.");
        }
    }

    //Метод для удаления книги из библиотеки по ID
    public void RemoveBook(int id)
    {
        if (books.ContainsKey(id))
        {
            books.Remove(id);
            Console.WriteLine($"Книга с ID {id} удалена из библиотеки.");
        }
        else
        {
            Console.WriteLine($"Книга с ID {id} не найдена в библиотеке.");
        }
    }

    //Метод для поиска книги по ID
    public Book FindBook(int id)
    {
        if (books.ContainsKey(id))
        {
            return books[id];
        }
        else
        {
            Console.WriteLine($"Книга с ID {id} не найдена в библиотеке.");
            return null;
        }
    }

    //Метод для вывода списка всех книг в библиотеке
    public void PrintAllBooks()
    {
        if (books.Count == 0)
        {
            Console.WriteLine("В библиотеке нет книг.");
            return;
        }

        Console.WriteLine("Список книг в библиотеке:");
        foreach (var book in books.Values) 
        {
            Console.WriteLine(book.ToString()); 
        }
    }

    // Метод для поиска книг по автору (возвращает список книг)
    public List<Book> FindBooksByAuthor(string author)
    {
        List<Book> foundBooks = new List<Book>();
        foreach (var book in books.Values)
        {
            if (book.Author.Equals(author, StringComparison.OrdinalIgnoreCase)) 
            {
                foundBooks.Add(book);
            }
        }

        return foundBooks;
    }
}
class Example
{
    static void Main(string[] args)
    {
        // Пример использования
        Library library = new Library();

        // Создаем несколько книг
        Book book1 = new Book("Преступление и наказание", "Ф.М. Достоевский", 1866, 1);
        Book book2 = new Book("Война и мир", "Л.Н. Толстой", 1869, 2);
        Book book3 = new Book("Мастер и Маргарита", "М.А. Булгаков", 1967, 3);

        // Добавляем книги в библиотеку
        library.AddBook(book1);
        library.AddBook(book2);
        library.AddBook(book3);
        Console.WriteLine();

        // Выводим список всех книг
        library.PrintAllBooks();
        Console.WriteLine();

        // Ищем книгу по ID
        Book foundBook = library.FindBook(2);
        if (foundBook != null)
        {
            Console.WriteLine($"Найденная книга: {foundBook}");
        }
        Console.WriteLine();

        // Удаляем книгу по ID
        library.RemoveBook(1);
        Console.WriteLine();

        // Выводим список всех книг после удаления
        library.PrintAllBooks();
        Console.WriteLine();

        // Поиск книг по автору
        List<Book> bulgakovBooks = library.FindBooksByAuthor("М.А. Булгаков");
        Console.WriteLine("Книги Булгакова:");
        foreach (var book in bulgakovBooks)
        {
            Console.WriteLine(book);
        }
        Console.WriteLine();

    }
}