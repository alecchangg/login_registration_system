#include <iostream>
#include <fstream>

void login_account();
void register_account();

int main(){
    int status;
    do {
        std::cout << "\n\n";
        std::cout << "****** Login or Register ******\n\n";
        std::cout << "1. Login to your account\n\n";
        std::cout << "2. Register for an account\n\n";
        std::cout << "3. Exit\n\n";
        std::cout << "*******************************\n\n";
        std::cin >> status;
        switch(status){
            case 1:
                login_account();
                break;
            case 2:
                register_account();
                break;
            case 3:
                break;
            default:
                std::cout << "Invalid Option...\n\n";
                break;
        }
    }while(status != 3);
    return 0;
}

void login_account(){
    std::string user;
    std::string password;
    std::string userCheck;
    std::string passwordCheck;
    std::ifstream userFile;
    std::cout << "\n\n************ Login ************\n\n";
    std::cout << "Username: ";
    std::cin >> user;
    userFile.open(user + ".txt");
    while(!userFile){
        userFile.close();
        std::cout << "\nUser does not exist...\n\n";
        std::cin >> user;
        userFile.open(user + ".txt");
    }
    std::cout << "\nPassword: ";
    std::cin >> password;
    getline(userFile, userCheck);
    getline(userFile, passwordCheck);
    if (userCheck == user && passwordCheck == password){
        std::cout << "\nWelcome " << user << "!";
    }
    else {
        std::cout << "\nIncorrect username or password";
    }
    std::cout << "\n\n*******************************\n\n";
}

void register_account(){
    std::string user;
    std::string password;
    std::ofstream userFile;
    std::ifstream checkFile;
    
    std::cout << "\n\n*********** Register ***********\n\n";
    std::cout << "Username: ";
    std::cin >> user;
    checkFile.open(user + ".txt");
    while (checkFile){
        checkFile.close();
        std::cout << "\nUser already Exists...\n\n";
        std::cin >> user;
        checkFile.open(user + ".txt");
    }
    std::cout << "\nPassword: ";
    std::cin >> password;
    userFile.open(user + ".txt");
    userFile << user + "\n";
    userFile << password;
    userFile.close();
    std::cout << "\n********************************\n\n";
}