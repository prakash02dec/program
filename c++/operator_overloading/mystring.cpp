#include "mystring.hpp"
#include <cstring>

mystring ::mystring()
    : str{nullptr}
{
    str = new char[1];
    *str = '\0';
}

mystring::mystring(const char *s)
    : str{nullptr}
{
    if (s == nullptr)
    {
        str = new char[1];
        *str = '\0';
    }
    else
    {
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }
}

mystring::mystring(const mystring &source)
    : str{nullptr}
{
    str = new char[strlen(source.str) + 1];
    strcpy(this->str, source.str);
}

mystring::mystring(mystring &&source)
    : str{nullptr}
{
    str = source.str;
    source.str = nullptr;
}

mystring &mystring::operator=(mystring &&source)
{
    if (this == &source)
        return *this;

    delete [] str;
    str=source.str;
    source.str=nullptr;
    return *this;

        
}

mystring &mystring::operator=(const mystring &source)
{
    if (this == &source)
        return *this;

    delete[] this->str;
    this->str = new char[strlen(source.str) + 1];
    strcmp(str, source.str);
    return *this;
}

mystring::~mystring()
{
    delete[] str;
}

void mystring::display()
{
    std::cout << str << "  :" << get_length() << std::endl;
}

int mystring::get_length() const { return strlen(str); }

const char *mystring::get_str() const { return str; }

bool operator==(const mystring &lhs , const mystring &rhs){
    return (strcmp(lhs.str, rhs.str) == 0); 
}

bool operator != (const mystring &lhs , const mystring &rhs ){
    return !(strcmp(lhs.str , rhs.str) ==0);
}
bool operator < (const mystring &lhs , const mystring &rhs ){
    return (strcmp(lhs.str, rhs.str) < 0);
}
bool operator > (const mystring &lhs , const mystring &rhs ){
    return (strcmp(lhs.str , rhs.str) > 0); 
}
mystring &operator += (mystring &lhs , const mystring &rhs ){
    lhs = lhs + rhs;
    return lhs ;
}
mystring operator * (const mystring &ref , int n ){
    mystring temp;
    temp.str = new char [strlen(ref.str)*n+1];

    for(size_t i=0 ; i < n ; i++){
        temp = temp + ref.str;
    }
    return temp;

}
mystring &operator *= (mystring &lhs , int n ){
    lhs = lhs*n;
    return lhs;
}
mystring &operator ++ (mystring &ref ){
    for (size_t i=0 ; i<strlen(ref.str) ; i++)
    ref.str[i] = toupper(ref.str[i]);
    return ref;
}
mystring operator ++ (mystring &ref , int ){
    mystring temp {ref};
    ref++;
    return temp;

}

mystring operator-(const mystring &ref){
    mystring temp {};
    temp.str = new char [strlen(ref.str) + 1];
    for(size_t i=0 ; i< strlen(ref.str); i++)
    temp.str[i] = tolower(ref.str[i]);
    return temp;
}

mystring operator+(const mystring &lhs , const mystring &rhs){
    mystring temp {};
    temp.str = new char [strlen(lhs.str) + strlen(rhs.str) + 1];
    strcpy(temp.str,lhs.str);
    strcat(temp.str,rhs.str);
    return temp;
}

std::ostream &operator<<(std::ostream &os , const mystring &ref){
    os << ref.str;
    return os;
}

std::istream &operator>>(std::istream &is , mystring &ref){
    char *buff { new char [10000] };
    is >> buff;
    mystring temp {buff};
    ref = temp;
    return is ;
}
