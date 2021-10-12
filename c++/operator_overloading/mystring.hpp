#ifndef _my_string_hpp_
#define _my_string_hpp_

#include <iostream>
class mystring{

    private:
    char * str ;
    public:
    mystring();
    mystring(const char *str);
    mystring(const mystring &source );
    mystring(mystring &&source);
    ~mystring();
    
    void display() const;
    int get_length() const;
    const char*get_str() const;


    mystring &operator=(const mystring &source);
    mystring &operator=(mystring &&source); discharge){

    void display();


    friend bool operator==(const mystring &lhs , const mystring &rhs );
    friend mystring operator-(const mystring &ref );
    friend mystring operator+(const mystring &lhs , const mystring &rhs );
    friend std::ostream &operator<<(std::ostream &os , const mystring &ref );
    friend std::istream &operator>>(std::istream &is , mystring &ref );
    friend bool operator != (const mystring &lhs , const mystring &rhs );
    friend bool operator < (const mystring &lhs , const mystring &rhs );
    friend bool operator > (const mystring &lhs , const mystring &rhs );
    friend mystring &operator += ( mystring &lhs , const mystring &rhs );
    friend mystring operator * (const mystring &ref , int n );
    friend mystring &operator *= (mystring &lhs , int n );
    friend mystring &operator ++ (mystring &ref );
    friend mystring operator ++ (mystring &ref , int );


    // friend bool operator==(const mystring &lhs , const mystring &rhs );
    // friend mystring operator-(const mystring &ref );
    // friend mystring operator+(const mystring &lhs , const mystring &rhs );
    // friend std::ostream &operator<<(std::ostream &os , const mystring &ref );
    // friend std::istream &operator>>(std::istream &is , mystring &ref );
    // friend bool operator != (const mystring &lhs , const mystring &rhs );
    // friend bool operator < (const mystring &lhs , const mystring &rhs );
    // friend bool operator > (const mystring &lhs , const mystring &rhs );
    // friend mystring &operator += (const mystring &lhs , const mystring &rhs );
    // friend mystring &operator * (const mystring &lhs , int n );
    // friend mystring &operator *= (const mystring &lhs , int n );
    // friend mystring &operator ++ (mystring &ref );
    // friend mystring &operator ++ (mystring &ref , int );

};


#endif 



