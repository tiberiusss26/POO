#include <iostream>
#include <vector>
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
    carte(){
        title = new char[0];
        main_author = new char[0];
        secondary_author = new char[0];
    };
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
    carte(carte& rhs)
    {
        size_t len1 = strlen(rhs.title);
        title = new char[len1];
        strcpy(title,rhs.title);
        size_t len2 = strlen(rhs.main_author);
        main_author = new char[len2];
        strcpy(main_author,rhs.main_author);
        size_t len3 = strlen(secondary_author);
        secondary_author = new char[len3];
        strcpy(secondary_author,rhs.secondary_author);
        pages=rhs.pages;
        price=rhs.price;
        rating=rhs.rating;

    }

    virtual ~carte() {
        delete[] title;
        delete[] main_author;
        delete[] secondary_author;

    }

    friend istream& operator >>(istream& is,carte& book){
            char buf[1000];
            int page_,price_,rating_;
            while(is>>buf){
            size_t len1 = strlen(buf);
            book.title = new char[len1];
            strcpy(book.title,buf);}
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
            return is;

    }
    friend ostream &operator<<(ostream&is,carte &book){
        is<<"Titul: "<<book.title<<"\n";
        is<<"Autor principal: "<<book.main_author<<"\n";
        is<<"Autor secundar: "<<book.secondary_author<<"\n";
        is<<"Numar pagini: "<<book.pages<<"\n";
        is<<"Pret: "<<book.price<<"\n";
        is<<"Rating: "<<book.rating<<".\n";
        return is;
    }
    void operator=(const carte &rhs){
        size_t len1 = strlen(rhs.title);
        title = new char[len1];
        strcpy(title,rhs.title);
        size_t len2 = strlen(rhs.main_author);
        main_author = new char[len2];
        strcpy(main_author,rhs.main_author);
        size_t len3 = strlen(secondary_author);
        secondary_author = new char[len3];
        strcpy(secondary_author,rhs.secondary_author);
        pages=rhs.pages;
        price=rhs.price;
        rating=rhs.rating;
    }
    void operator>(const carte &rhs){
        if(rating>rhs.rating) cout<<"Prima carte este mai buna";
        else if(rating==rhs.rating) cout<<"Cartile sunt la fel de bune";
        else cout<<"A doua carte este mai buna";
    }
};
int main() {
carte C1("Punguta cu doi bani","Ioan slavici","ion creanga",300,24.30,5);
carte C2("Ana","are","mere",200,300,3);
carte C3;
carte C4;
carte C5=C1;
carte C6(C5);
C3 = C1;
C4 = C2;
carte C8;
cin>>C8;
cout<<C8;
//carte C5=C2; carte C5(C2)
//cout<<C1<<C2<<C3<<C4<<C5<<C6;
C2>C1;
//vector<carte> carti;
//carte carte;
//for(int i=0;i<3;i++) {cin>>carte[i];carti.push_back(carte[i]);}
//for(int i=0;i<3;i++) cout<<carti[i];
}
