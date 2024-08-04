#include<iostream>

// we are implement it using 3 column representation or coordinate-list method
struct element{
    int i ; // row 
    int j ; // col
    int x ; // element 
};

struct sparsh_matrix{
    int m {}; // m*n matrix dimension
    int n {}; 
    int num {}; // no of non zero element
    element *ele {} ; // array of element
};

void create(sparsh_matrix *s){
    std::cout << "Enter the dimension of the matrix" << std::endl ; 
    std::cin >> s->m >> s->n ;
    std::cout << "Enter the no of non zero element in the matrix" << std::endl ; 
    std::cin >> s->num ; 
    s->ele = new element [s->num] ;
    std::cout << "Enter the coordinates with the respective elements" << std::endl ;
    std:: cout << "i  j  x" << std::endl ; 
    for (int i {} ; i < s->num ; i++){
        std::cin >> s->ele[i].i >> s->ele[i].j >> s->ele[i].x ; 
    }
}

void display(sparsh_matrix s){
    int k {} ;
    for(int i {} ; i < s.m ; i++){
        for(int j {} ; j < s.n ; j++ ){
            if(i== s.ele[k].i && j==s.ele[k].j)
                std::cout << s.ele[k++].x << " " ;
            else 
                std::cout << "0 " ; 
        }
        std::cout << std::endl ; 
    }
}

sparsh_matrix* add(sparsh_matrix s1 , sparsh_matrix s2){
    if( s1.m != s2.m || s1.n != s2.n ){
        return nullptr ;     
    }
    sparsh_matrix *sum {new sparsh_matrix} ;
    sum->m = s1.m ;
    sum->n = s2.n ; 
    sum->ele = new element [s1.num + s2.num ] ;
    int k {} , i {} , j {};
    while(i < s1.num && j < s2.num ){
        if(s1.ele[i].i < s2.ele[j].i)
            sum->ele[k++] = s1.ele[i++] ;
        else if(s1.ele[i].i > s2.ele[j])
            sum->ele[k++] = s2.ele[j++] ;
        else{
            if(s1.ele[i].j < s2.ele[j].j)
                sum->ele[k++] = s1.ele[i++] ;
            else if(s1.ele[i].j > s2.ele[j].j)
                sum->ele[k++] = s2.ele[j++] ;
            else{
                sum->ele[k] = s1.ele[i++] ;
                sum->ele[k++].x += s2.ele[j++].x ;
            } 
        }
    }
    while(i<s1.num){
        sum->ele[k++] = s1.ele[i++] ;
    }
    while(j<s2.num){
        sum->ele[k++] = s2.ele[j++] ;
    }
    sum->num = k ;
    return sum ;

}
int main (){
    sparsh_matrix s1 , s2 ;
    create(&s1) ;
    create(&s2) ;
    display(s1) ;
    return 0 ;
}