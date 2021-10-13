 #include"mystring.hpp"
 #include <cstring>
 #include <iostream>
 mystring :: mystring()
 :str{nullptr}{
     str = new char[1];
     *str = '\0';

 }

mystring::mystring(const char *s)
:str{nullptr}{
    if(s==nullptr){
    str = new char[1];
    *str = '\0';
    }
    else{
        str = new char[strlen(s)+1];
        strcpy(str,s);
    }
}

mystring::mystring(const mystring &source)
:str{nullptr}{
    if(source.str==nullptr){
        str = new char [1];
        str ='\0';
    }
    else{
        str = new char[strlen(source.str)+1];
        strcpy(this->str, source.str);
    }
}
mystring &mystring::operator=(const mystring &source){
    if(this == &source)
    return *this;

    delete [] this->str;
    this->str= new char[strlen(source.str)+1];
    strcmp(str, source.str);
    return *this;
}
mystring::~mystring(){
    delete [] str;
}

void mystring::display(){
    std::cout<<str<<"  :"<<get_length()<<std::endl;
}

int mystring::get_length() const {return strlen(str); }

const char *mystring::get_str() const{return str;}