#include <iostream>
#include <cstring>
using namespace std;
class carte{
//    char *book;
    char *title;
    char *main_author;
    char *secondary_author;
    int pages;
    float price;
    int rating;
    bool empty = true;
public:
    carte(const char *title_,char *main_author_, char *secondary_author_, int pages_, float price_, int rating_){
        size_t len1 = strlen(title_);
        title = new char[len1];
        strcpy(title,title_);
        size_t len2 = strlen(main_author_);
        main_author = new char[len2];
        strcpy(main_author,main_author_);
        size_t len3 = strlen(secondary_author_);
        secondary_author = new char[len3];
        strcpy(secondary_author,secondary_author_);
        pages = pages_;
        price = price_;
        rating = rating_;
        empty = false;
    }

    virtual ~carte() {
        delete[] title;
        delete[] main_author;
        delete[] secondary_author;
    }

    void afis(){
        cout<<title;
    }
    friend istream& operator >>(istream& is,carte&book){
            char buf[100];
            int page_,price_,rating_;
            is>>buf;
            size_t len1 = strlen(buf);
            book.title = new char[len1];
            strcpy(book.title,buf);
            is>>buf;
            size_t len2 = strlen(buf);
            book.main_author = new char[len2];
            strcpy(book.main_author,buf);
            is>>buf;
            size_t len3 = strlen(buf);
            book.secondary_author = new char[len3];
            strcpy(book.secondary_author,buf);
            is>>page_;
            book.pages=page_;
            is>>price_;
            book.price=price_;
            is>>rating_;
            book.rating=rating_;

    }
};
int main() {
carte C1("Punguta cu doi bani","Ioan slavici","ion creanga",300,24.30,5);
carte C2("Ana","are","mere",200,300,3);
carte C3("a","","",0,0,0);
cin>>C3;
C3.afis();
}
