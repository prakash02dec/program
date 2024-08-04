#include <iostream>

class Element{
    
    public:
    int i;
    int j;
    int x;
};

class Sparse_matrix{
    
    private:
    int m;
    int n;
    int num;
    Element *ele;

    public:
    Sparse_matrix(int m,int n,int num)
    : m{m} , n{n} , num{num} , ele {std::move(ele=new Element[num] )}
    {}
    ~Sparse_matrix()
    {
        delete [] ele;
    }
 
    Sparse_matrix operator+(Sparse_matrix &s);
 
    friend std::istream& operator>>(std::istream &is , Sparse_matrix &s);
    friend std::ostream& operator<<(std::ostream &os , Sparse_matrix &s);
 
 
};

Sparse_matrix Sparse_matrix::operator+(Sparse_matrix &s){

    if(m!=s.m || n!=s.n)
        return Sparse_matrix(0,0,0);
    
    Sparse_matrix *sum=new Sparse_matrix(m,n,num+s.num);
    int i{} , j{} , k{} ;
    while(i<num && j<s.num){
        if(ele[i].i<s.ele[j].i)
            sum->ele[k++]=ele[i++];
        else if(ele[i].i > s.ele[j].i)
            sum->ele[k++]=s.ele[j++];
        else
        {
            if(ele[i].j<s.ele[j].j)
                sum->ele[k++]=ele[i++];
            else if(ele[i].j > s.ele[j].j)
                sum->ele[k++]=s.ele[j++];
            else{
                sum->ele[k]=ele[i];
                sum->ele[k++].x=ele[i++].x+s.ele[j++].x;
            }
        }
    }
    while(i < num)
        sum->ele[k++]=ele[i++];
    while(i < s.num)
        sum->ele[k++]=s.ele[i++];
    
    return *sum;
 
}

// not implemented yet
std::istream& operator>>(std::istream &is,Sparse_matrix &s){
    std::cout <<"Enter non-zero elements" << std::endl ;
    is>>s.num;
    std::cout << "i j x" <<std::endl ;
    for(int i=0;i<s.num;i++)
        std::cin>>s.ele[i].i>>s.ele[i].j>>s.ele[i].x;
    return is;
}

std::ostream& operator<<(std::ostream &os,Sparse_matrix &s)
{
    int k=0;
    for(int i=0;i<s.m;i++){
        for(int j=0;j<s.n;j++){
            
            if(s.ele[k].i==i && s.ele[k].j==j)
                os << s.ele[k++].x << " ";
            else
            os << "0 ";
        }
        os << std::endl;
    }
    return os;
}
 
int main(){
    Sparse_matrix s1(5,5,5);
    Sparse_matrix s2(5,5,5);
 
    std::cin >> s1;
    std::cin >> s2;
    
    Sparse_matrix sum=s1+s2;
    
    std::cout <<"First Matrix" << std::endl<<s1;
    std::cout <<"Second MAtrix" << std::endl<<s2;
    std::cout <<"Sum Matrix" << std::endl<<sum;
    
    return 0;
}