#ifndef _my_string_hpp_

#define _my_string_hpp_

class mystring{
    private:
    char * str ;
    public:
    mystring();
    mystring(const char *str);
    mystring(const mystring &source );
    ~mystring();
    
    void display() const;
    int get_length() const;
    const char*get_str() const;
    mystring & operator=(const mystring &source);
    void display();

};


#endif 



