#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

class Book {
private:
    char* title;
    char* author;
    int pageCount;
    bool formatType;
    float* chapterPages;
    int numChapters;

public:
    // Default Constructor
    Book() {
        title = new char[1];
        title[0] = '\0';
        author = new char[1];
        author[0] = '\0';
        pageCount = 0;
        formatType = false;
        chapterPages = NULL;
        numChapters = 0;
    }

    // Parameterized Constructor
    Book(const char* t, const char* a, int pc, bool ft, int nc) {
        title = new char[strlen(t) + 1];
        strcpy(title, t);
        author = new char[strlen(a) + 1];
        strcpy(author, a);
        pageCount = pc;
        formatType = ft;
        numChapters = nc;
        chapterPages = new float[nc];
        for (int i = 0; i < nc; i++) {
            chapterPages[i] = (float)pc / nc;
        }
    }

    // Copy Constructor
    Book(const Book& b) {
        title = new char[strlen(b.title) + 1];
        strcpy(title, b.title);
        author = new char[strlen(b.author) + 1];
        strcpy(author, b.author);
        pageCount = b.pageCount;
        formatType = b.formatType;
        numChapters = b.numChapters;
        chapterPages = new float[numChapters];
        for (int i = 0; i < numChapters; i++) {
            chapterPages[i] = b.chapterPages[i];
        }
    }

    // Destructor
    ~Book() {
        delete[] title;
        delete[] author;
        delete[] chapterPages;
    }

    // Utility Methods
    void modifyChapterPages(int chapter, float pages) {
        if (chapter >= 0 && chapter < numChapters) {
            chapterPages[chapter] = pages;
        }
    }

    void displayBookInfo() {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Page Count: " << pageCount << endl;
        cout << "Format Type: " << (formatType ? "Hardcover" : "Paperback") << endl;
        cout << "Number of Chapters: " << numChapters << endl;
        cout << "Chapter Pages: ";
        for (int i = 0; i < numChapters; i++) {
            cout << chapterPages[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    // Test Default Constructor
    Book book1;
    book1.displayBookInfo();

    // Test Parameterized Constructor
    Book book2("Book Title", "Author Name", 200, true, 5);
    book2.displayBookInfo();

    // Test Copy Constructor
    Book book3(book2);
    book3.displayBookInfo();

    // Test Utility Methods
    book2.modifyChapterPages(2, 50);
    book2.displayBookInfo();

    return 0;
}
