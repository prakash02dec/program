#include <iostream>
#include <cmath>

class Terms{
    public:
    int coeff ;
    int exp ;
};

class Polynomial{
    private:
    int n;
    Terms *t ;
    public:
     
    Polynomial(int n=3)
    : n{n} , t{std::move(new Terms [n])} {}
    
    Polynomial(const Polynomial &src)
    : n {src.n} , t {std::move(new Terms [n])}{
        for(int i {} ; i < n ; i++)
            t[i] = src.t[i] ;
    }


    ~Polynomial(){
        delete [] t ;
    }

    friend std::istream& operator>>(const std::istream &is , Polynomial &p);
    friend std::ostream& operator<<(const std::ostream &os , const Polynomial &p);
    Polynomial operator+(const Polynomial &rhs) const ;

};

std::istream& operator>>(const std::istream &is , Polynomial &p){
    std::cout << "Enter the no of polynomial terms : " ;
    std::cin >> p.n ;
    p.t = new Terms [p.n] ;
    std::cout << "Enter the polynomial terms now" << std::endl ;
    for(int i {} ; i < p.n ; i++){
        std::cout << "Term no " << i+1 << std::endl ;
        std::cin >> p.t[i].coeff >> p.t[i].exp ;
    }
}

std::ostream& operator<<(const std::ostream &os , const Polynomial &p){
    std::cout << "Polynomial Expresion : " ;
    for(int i {} ; i < p.n-1 ; i++){
        std::cout << p.t[i].coeff << "x^" << p.t[i].exp << " + " ; 
    }
    std::cout << p.t[p.n-1].coeff << "x^" << p.t[p.n-1].exp << std::endl;
    
    std::cout << "Polynomial Evaluation " << std::endl ; 
    int x {} ; 
    std::cin >> x ; 
    int sum {} ;
    for(int i {} ; i < p.n ; i++){
        sum += p.t[i].coeff * std::pow(x , p.t[i].exp ) ; 
    }
}

Polynomial Polynomial::operator+(const Polynomial &rhs) const{
    Polynomial p {this->n + rhs.n} ;
    int i {} , j {} , k{} ;
    while( i < this->n && j < rhs.n ){
        if(this->t[i].exp > rhs.t[j].exp) 
            p.t[k++] = this->t[i++] ; 
        else if(this->t[i].exp < rhs.t[j].exp) 
            p.t[k++] = rhs.t[j++] ;
        else{
            p.t[k] = this->t[i++] ;
            p.t[k++].coeff += rhs.t[j++].coeff ;
        }
        
    }

    while(i < this->n){
        p.t[k++] = this->t[i++] ;
    }
    while(j < rhs.n){
        p.t[k++] = rhs.t[i++] ;
    }
    p.n = k ;

    return p ;

}

int main (){

    Polynomial p1(5) , p2(6) ;
    std::cin >> p1 ;
    std::cin >> p2 ;

    Polynomial p3{p1+p2} ;

    std::cout << p1 ;
    std::cout << p2 ;
    std::cout << p3 ; 

    return 0 ;
} 


