#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Author {
private:
    string name, mail, gender;

public:
    Author(string name, string mail, string gender) {
        this->name = name;
        this->mail = mail;
        this->gender = gender;
    }

    string toString() {
        return "Name : " + this->name + "\n" + "Email : " + this->mail + "\n" + "Gender : " + this->gender;
    }
};
class Book {
private:
    string name;
    vector<Author> authors;
    double price;
    int qty;

public:
    Book() {}

    Book(string name, vector<Author> authors, double price, int qty) {
        this->name = name;
        this->authors = authors;
        this->price = price;
        this->qty = qty;
    }

    string getName() {
        return this->name;
    }

    void showInfor() {
        cout << "-----------------------\nBook information :\n"
             << "Name : " << this->name << "\n"
             << "Price : " << (int)this->price << "\n"
             << "Quantity : " << this->qty << "\n"
             << "Author information :\n";
        for (int i = 0; i < authors.size(); i++) {
            cout << "#" << (i + 1) << "\n" << authors[i].toString() << "\n";
        }
    }
};
void sapXep(vector<Book>& books) {
    sort(books.begin(), books.end(), [](Book& b1, Book& b2) {
        return b1.getName() < b2.getName();
    });
}
int main() {
    vector<Book> listBook; 

    int t;
    cin >> t;
    cin.ignore();
    while (t-- > 0) {
        string tmp;
        getline(cin, tmp); 
        string tenSach;
        getline(cin, tenSach);

        double price;
        int qty, n;
        cin >> price >> qty >> n;
        cin.ignore();

        vector<Author> listAuthor;
        for (int i = 0; i < n; i++) {
            string name, mail, gender;
            getline(cin, name);
            getline(cin, mail);
            getline(cin, gender);
            listAuthor.push_back(Author(name, mail, gender));
        }

        listBook.push_back(Book(tenSach, listAuthor, price, qty));
    }

    sapXep(listBook); 

    for (auto& book : listBook) {
        book.showInfor(); 
    }

    return 0;
}
