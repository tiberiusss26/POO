#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
class carte{
    char *title;
    char *main_author;
    char *secondary_author;
    int pages;
    float price;
    int rating;
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
//        empty = false;
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
//        cout<<"folosit"<<endl;
        delete[] title;
        delete[] main_author;
        delete[] secondary_author;

    }

    friend istream& operator >>(istream& is,carte& book){
            char buf[1000];
            int page_,rating_;
            float price_;
            cout<<"Titlu: ";
            is.getline(buf,sizeof(buf));
            size_t len1 = strlen(buf);
            book.title = new char[len1];
            strcpy(book.title,buf);
            cout<<"Autor principal: ";
            is.getline(buf,sizeof(buf));
            size_t len2 = strlen(buf);
            book.main_author = new char[len2];
            strcpy(book.main_author,buf);
            cout<<"Autor secundar: ";
            is.getline(buf,sizeof(buf));
            size_t len3 = strlen(buf);
            book.secondary_author = new char[len3];
            strcpy(book.secondary_author,buf);
            cout<<"Numar pagini: ";
            is>>page_;
            book.pages=page_;
            cout<<"Pret: ";
            is>>price_;
            book.price=price_;
            cout<<"Rating: ";
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

    bool operator< (const carte& rhs) const { return!(rhs.rating<= this->rating); }
    bool operator> (const carte& rhs) const { return rhs.rating < this->rating; }
    bool operator>= (const carte& rhs) const { return !(rhs.rating < this->rating); }

    void setTitle(const char *title_) {
        size_t len = strlen(title_);
        this->title = new char [len];
        strcpy(this->title, title_);

    }

    void setMainAuthor(char *mainAuthor) {
        size_t len = strlen(mainAuthor);
        this->main_author = new char [len];
        strcpy(this->main_author, mainAuthor);
    }

    void setSecondaryAuthor(char *secondaryAuthor) {
        size_t len = strlen(secondaryAuthor);
        this->secondary_author = new char [len];
        strcpy(this->secondary_author, secondaryAuthor);
    }

    void setPages(int pages) {
        carte::pages = pages;
    }

    void setPrice(float price) {
        carte::price = price;
    }

    void setRating(int rating) {
        carte::rating = rating;
    }

};

int main() {
vector <carte*> v;
char buff[1000];

cout<<"Comanda: "; cin>>buff;
while(strcmp(buff,"STOP")!=0){
    cin.get();

    if(strcmp(buff,"ADD")==0){
        carte* C = new carte;
        cin>>*C;
        v.push_back(C);}

    if(strcmp(buff,"SHOW")==0){
        for(auto it:v) cout<<*it<<endl;
    }

    if(strcmp(buff,"MOD_TITLU")==0){
        cout<<"Cartea pentru care modific: ";
        int x;
        cin>>x;
        char nou[100];
        cout<<"Noul titlu: ";
        cin.get();
        cin.getline(nou,sizeof(nou) );
        v[x]->setTitle(nou);
    }

    if(strcmp(buff,"MOD_AUT1")==0){
        cout<<"Cartea pentru care modific: ";
        int x;
        cin>>x;
        cout<<"Numele noului autor: ";
        char nou[100];
        cin.get();
        cin.getline(nou,sizeof(nou) );
        v[x]->setMainAuthor(nou);
    }

    if(strcmp(buff,"MOD_AUT2")==0){
        cout<<"Cartea pentru care modific: ";
        int x;
        cin>>x;
        char nou[100];
        cout<<"Numele noului atuor: ";
        cin.get();
        cin.getline(nou,sizeof(nou) );
        v[x]->setSecondaryAuthor(nou);
    }

    if(strcmp(buff,"MOD_PG")==0){
        int x;
        cout<<"Cartea pentru care modific: ";cin>>x;
        int y;
        cout<<"Noul numar de pagini: "; cin>>y;
        v[x]->setPages(y);
    }

    if(strcmp(buff,"MOD_PRET")==0){
        int x;
        cout<<"Cartea pentru care modific: ";cin>>x;
        float y;
        cout<<"Noul pret: "; cin>>y;
        v[x]->setPrice(y);
    }

    if(strcmp(buff,"MOD_RTG")==0){
        int x;
        cout<<"Cartea pentru care modific: ";cin>>x;
        int y;
        cout<<"Noul numar de pagini: "; cin>>y;
        v[x]->setRating(y);
    }

    if(strcmp(buff,"CMP")==0){
        int x,y;
        cout<<"Prima carte: ";cin>>x;
        cout<<"A doua carte: "; cin>>y;
        if(*v[x]>*v[y]) cout<<"Prima carte este mai buna."<<endl;
        else if(*v[x]<*v[y]) cout<<"A doua carte este mai buna."<<endl;

//        else if(*v[x]>=*v[y]) cout<<"Ambele carti sunt la fel de bune"<<endl;
        else cout<<"Ambele carti sunt la fel de bune."<<endl;
    }

    if(strcmp(buff,"CMP")!=0 && strcmp(buff,"MOD_RTG")!=0 && strcmp(buff,"MOD_PRET")!=0 && strcmp(buff,"MOD_PG")!=0 && strcmp(buff,"MOD_AUT2")!=0 && strcmp(buff,"MOD_AUT1")!=0 && strcmp(buff,"MOD_TITLU")!=0 && strcmp(buff,"ADD")!=0 && strcmp(buff,"SHOW")!=0){
        cout<<"Command not found.\n";
    }

    cout<<"Comanda: ";
    cin>>buff;
}}
