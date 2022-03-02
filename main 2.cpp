#include <iostream>
#include <cstring>
using namespace std;
class carte{
    char *books;
    char main_author;
    char secondary_author;
    int pages;
    float price;
    int rating;
public:
    carte(const char *book,char main_author_, char secondary_author_, int pages_, float price_, int rating_){
        size_t len = strlen(book);
        book = new char[len];
        strcat(books,book);
        main_author = main_author_;
        secondary_author = secondary_author_;
        pages = pages_;
        price = price_;
        rating = rating_;
    }

    virtual ~carte() {
        delete[] books;

    }
};
int main() {
    return 0;
}
