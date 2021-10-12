
//                     CIPHER
#include<iostream>
#include<string>

int main(){
    std::cout<<std::endl;
    std::string alphabet {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    std::string key {"XZNLWEBGJHQDYVTKFUOMPCIASRxznlwebgjhqdyvtkfuompciasr"};

    std::string secret_message;
    std::cout<<"Enter your secret message : ";
    getline(std::cin,secret_message);

    std::string encrypted_message {};
    std::cout<<"\nEncrypting message..."<<std::endl;

    for(auto c: secret_message){
        size_t position=alphabet.find(c);
        if( position != std::string::npos)  encrypted_message += key.at(position);
        else   encrypted_message +=c;
    }

    std::cout<<"\nEncrypted message : "<<encrypted_message<<std::endl;

    std::cout<<std::endl;
    return 0;
}