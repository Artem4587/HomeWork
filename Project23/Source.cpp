#include <iostream>
#include <string>

using namespace std;

class Book {
private:
    string title;  
    string author; 
    int year;     
    int id;       

public:
    Book(string titleValue, string authorValue, int yearValue, int idValue)
    {
        title = titleValue;
        author = authorValue;
        year = yearValue;
        id = idValue;
    }
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    int getYear() const { return year; }
    int getId() const { return id; }

    void display() const {
        cout << "ID: " << id << endl;
        cout << "��������: " << title << endl;
        cout << "�����: " << author << endl;
        cout << "���: " << year << endl;
        cout << "-----------------------------" << endl;
    }
};

class Library {
private:
    static const int TABLE_SIZE = 100; 
    Book* books[TABLE_SIZE];    

    int hashFunction(int id) const {
        return id % TABLE_SIZE;
    }

public:
    Library() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            books[i] = nullptr;
        }
    }
    void addBook(const Book& book) {
        int index = hashFunction(book.getId());
        while (books[index] != nullptr) {
            index = (index + 1) % TABLE_SIZE; 
        }
        books[index] = new Book(book);
        cout << "����� ������� ���������!" << endl;
    }
    void removeBook(int id) {
        int index = hashFunction(id);
        while (books[index] != nullptr) {
            if (books[index]->getId() == id) {
                delete books[index];
                books[index] = nullptr;
                cout << "����� ������� �������!" << endl;
                return;
            }
            index = (index + 1) % TABLE_SIZE; 
        }
        cout << "����� �� �������!" << endl;
    }
    void searchBook(int id) const {
        int index = hashFunction(id);
        while (books[index] != nullptr) {
            if (books[index]->getId() == id) {
                books[index]->display();
                return;
            }
            index = (index + 1) % TABLE_SIZE; 
        }
        cout << "����� �� �������!" << endl;
    }
    void displayAllBooks() const {
        bool hasBooks = false;
        for (int i = 0; i < TABLE_SIZE; ++i) {
            if (books[i] != nullptr) {
                books[i]->display();
                hasBooks = true;
            }
        }
        if (!hasBooks) {
            cout << "� ���������� ��� ����!" << endl;
        }
    }
    ~Library() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            if (books[i] != nullptr) {
                delete books[i];
            }
        }
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    Library library; 
    library.addBook(Book("������� ������", "�. ����� �����������", 1925, 1));
    library.addBook(Book("����� ������������", "������ ��", 1960, 2));
    library.addBook(Book("1984", "������ ������", 1949, 3));
    cout << "��� ����� � ����������:" << endl;
    library.displayAllBooks();
    cout << "����� ����� � ID 2:" << endl;
    library.searchBook(2);
    cout << "�������� ����� � ID 1:" << endl;
    library.removeBook(1);
    cout << "��� ����� � ���������� ����� ��������:" << endl;
    library.displayAllBooks();
}