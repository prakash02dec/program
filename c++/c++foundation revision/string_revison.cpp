#include<string>
#include<iostream>

int main(){
    std::string s1;               // empty string initiallize
    std::string s2 {"frank"};     // frank
    std::string s3 {s2};          // frank but different memory location
    std::string s4 {"frank",3};   // fra
    std::string s5 {"frank",0,2}; //fr  or {s2,0,3}  //app
    std::string s6 {3,'X'};       //XXX
    

    s1="c++ Rocks!";
    std::string s7 {"hello"};
    s2=s1;


    std::string part1 {"c++"};
    std::string part2 {"is a powerfull"};
    
    std::string sentence;
    sentence=part1+" "+part2+ " language";  //c++ is a powerfull langauge

    // sentence="c++" + "is powerfull";     // illegal == not works with c literals . 
   //it works with c++ string and mix of c and c++ string

    std::cout<<s2[0]<<std::endl;
    std::cout<<s2.at(0)<<std::endl;

    s2[0]='F';
    s2.at(0)='p';

    for(char c:s1)
        std::cout<<c<<std::endl;

  /*f
    r
    a
    n
    k
    null character
    thier respective ascii value if it changes to int from char*/


    std::string s8 {"this is a test"};
    std::cout<<s8.substr(0,4)<<std::endl;
    std::cout<<s8.substr(5,2)<<std::endl;
    std::cout<<s8.substr(10,4)<<std::endl;
    

    std::cout<<s1.find("this");     // return the starting index 0
    std::cout<<s1.find("is");       // 2
    std::cout<<s1.find("test");     // 10
    std::cout<<s1.find("e");        // 11
    std::cout<<s1.find("is",4);     // 5
    std::cout<<s1.find("XX");       // string::npos

    // erase(start index, lenght);
    s1.erase(0,5);  // is a test
    s1.erase(5,4);  // is a
    s1.clear();   // empty string
    s1.length();

    // to words with spaces
    getline(std::cin ,s1);
    std::cout<<s1<<std::endl;
    getline(std::cin,s1,'x');  //stops taking input when x appear 
    std::cout<<s1<<std::endl;


    std::string s10 {"The secret word is Boo"};
    std::string word;

    word="boo";

    size_t position=s10.find(word);
    if(position!=std::string::npos) std::cout<<"found"<<word<<"at postion"<<position;
    else std::cout<<"sorry"<<word<<"not found"<<std::endl;

    std::cout<<std::endl;
    return 0;



}