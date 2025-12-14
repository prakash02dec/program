#include<bits/stdc++.h>

char digitToChar(int digit){
    return digit+'0' ;
}

int charToDigit(char ch){
    return ch - '0' ;
}

std::string addNumbers(std::string num1 , std::string num2){
    // make sure N2 is larger
    if(num1.length()>num2.length())
        std::swap(num1,num2);
    // result
    std::string result = "" ;
    // reverse 
    std::reverse(num1.begin(), num1.end()) ;
    std::reverse(num2.begin() , num2.end()) ; 

    // add digit upto a n1.length()
    int carry {} ;
    for(int i{} ; i < static_cast<int>(num1.length()) ; i++){
        int d1 {charToDigit(num1[i])};
        int d2 {charToDigit(num2[i])};
        int sum {d1+d2+carry} ;
        carry = sum/10 ;
        int outputDigit {sum%10} ;
        result.push_back(digitToChar(outputDigit)) ;
    
    }

    for(int i {static_cast<int>(num1.length())} ; i < static_cast<int>(num2.length()) ; i++ ){
        int d2 {charToDigit(num2[i])} ;
        int sum {d2+carry} ;
        carry = sum/10 ;
        int outputDigit {sum%10} ; 
        result.push_back(digitToChar(outputDigit)) ;
    }
    
    // finally if a carry is generated 
    if (carry) result.push_back('1');
    // reverse the final result  
    std::reverse(result.begin() ,result.end() ) ;
    return result ;
}

  
int main() {
    // string  
    std::string num1{} , num2{} ;
    std::cin>>num1 >> num2 ;
    std::string result {addNumbers(num1 , num2)} ;
    std::cout << result ; 
    return 0 ;
}


