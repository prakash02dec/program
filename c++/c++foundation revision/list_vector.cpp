#include<iostream>
#include<vector>
#include<cctype>


void display_menu()
{
    std::cout<<"\nP - Print numbers"<<std::endl;
    std::cout<<"A - Add a Number"<<std::endl;
    std::cout<<"M - Display mean of the numbers"<<std::endl;
    std::cout<<"S - Display the smallest number"<<std::endl;
    std::cout<<"L - Display the largest number "<<std::endl;
    std::cout<<"Q - Quit"<<std::endl;
    std::cout<<"Enter your choice below"<<std::endl;
}

char get_selection()
{
    char selection;
    std::cin>>selection;
    return toupper(selection);
}

void display_list(const std::vector<int> &numbers){
    std::cout<<"[ ";    
    
    for(auto number: numbers)
        std::cout<<number<<" ";
    
    std::cout<<"]";
}

void print_number( const std:: vector<int> &numbers)
{
    if(numbers.size()){
        display_list(numbers);
    }
    else 
    std::cout<<"[]-list is empty";
}

void add_number( std::vector<int> numbers)
{   
    int number {};
    std::cout<<"Enter the number you to add in the list"<<std::endl;
    std::cin>>number;
    numbers.push_back(number);
    std::cout<<number<<"is added";      
}

int calculate_total(int &total,const std::vector<int> &numbers){
    for(auto number: numbers)
        total+=number;
    return total;
}

void calculate_mean(const std::vector<int> &numbers)
{
    if(numbers.size()==0) std::cout<<"Empty list-Mean cannot be calculated ";
    else{
            int total {};
            total=calculate_total(total,numbers);
            std::cout<<"Mean is "<<static_cast<double>(total/numbers.size());
        }
} 

void smallest_number( const std::vector<int> &numbers)
{
    if(numbers.size()==0) std::cout<<"Empty list- unable to determine smallest number";
    else{
            int smallest {numbers.at(0)};
            for(auto number:numbers)
                if(number<smallest)
                    smallest=number;
            std::cout<<"The smallest number is "<<smallest;
        }
}  

void largest_number(const std::vector<int> &numbers)
{
    if(numbers.size()==0) std::cout<<"Empty list - unable to determine largest number";
    else{
            int largest {numbers.at(0)};
                for(auto number:numbers)
                    if(number>largest)
                    largest=number;
            std::cout<<"The largest number is "<<largest;
        }
}

void quit()
{
    std::cout<<"Exiting...  Good Bye ";
}

int main(){
    std::vector <int> numbers {};
    char selection {};

    do{
        display_menu();
        selection=get_selection();
        switch (selection)
        {
        case 'P':
            print_number(numbers);
            break;
        
        case 'A':
            add_number(numbers);
            break;
        
        case 'M':
            calculate_mean(numbers);
            break;

        case 'S':
            smallest_number(numbers);
            break;

        case 'L':
            largest_number(numbers);
            break;
        
        case 'Q':
            quit();
            break;
        
        default:
            std::cout<<"wrong selection";
            break;
        }
    }while(selection !='Q');
    
    std::cout<<std::endl;
    return 0;

}