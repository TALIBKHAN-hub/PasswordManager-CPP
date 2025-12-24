#include<iostream>
#include<fstream>
#include<limits>
#include<cstdlib>
#include<ctime>
using namespace std;

class passmanage{
    private:
        string password[100];
        string username[100];
        string platform[100];
    public:
        void menu();
        void addpu();
        void chk_pass();
        void chk_user();
        void upd_pass();
        void upd_user();
        void gene_pass();
};
void passmanage::menu(){
    system("cls");
    int choice;
    string option;
    cout<<"*****PASSWORD MANAGER*****"<<endl;
    cout<<"*****Made by TALIB*****"<<endl;
    cout<<"1. ADD password/username."<<endl;
    cout<<"2. Password Checker."<<endl;
    cout<<"3. Username Checker."<<endl;
    cout<<"4. Password Update."<<endl;
    cout<<"5. Username Update."<<endl;
    cout<<"6. Generate Password. "<<endl;
    cout<<"7. EXIT."<<endl;
    do{
        cout<<"ENTER your choice: ";
        cin>>choice;
        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout<<"!!!!!!INVAILD INPUT!!!!!!"<<endl;
            cout<<"TRY AGAIN [yes/no] : ";
            cin>>option;
            if(option =="yes"){
                continue;
            }else{
                cout<<"CLOSING......"<<endl;
                break;
            }
        }
        break;
        
    }while(true);
        
    switch (choice)
        {
        case 1:
            passmanage::addpu();
            break;
        case 2:
            passmanage::chk_pass();
            break;
        case 3:
            passmanage::chk_user();
            break;
        case 4:
            passmanage::upd_pass();
            break;
        case 5:
            passmanage::upd_user();
            break;
        case 6:
            passmanage::gene_pass();
            break;
        case 7:
            cout<<"CLOSING...."<<endl;
        default:
            break;
    }
}
void passmanage::addpu(){
    system("cls");
    string des;
    int value;
    for(int i=0;true;i++){
        cout<<"Enter USERNAME: "<<endl;
        cin>>username[i];
        cout<<"Enter PASSWORD: "<<endl;
        cin>>password[i];
        cout<<"Enter PLATFORM: "<<endl;
        cin>>platform[i];
        cout<<"USERNAME & PASSWORD successfully saved..."<<endl;
        cout<<"Save Another PASS/USER [yes/no]: ";
        cin>>des;
        if(des=="yes"){
            continue;
        }else{
            break;
        }
    }
    cout<<"ENTER [1 = HOME/2 = EXIT].."<<endl;
    cin>>value;
    if(value == 1){
        passmanage::menu();
    }else if (value == 2)
    {
        system("cls");
        cout<<"EXITING......"<<endl;
    }
    
}
void passmanage::chk_pass(){
    system("cls");
    string user_val;
    int value;
    cout<<"Enter USERNAME: ";
    cin>>user_val;
    bool found = false;
    for(int i=0;i<100;i++){
        if(username[i] == user_val){
            cout<<"PASSWORD: "<<password[i]<<endl;
            cout<<"PLATFORM: "<<platform[i]<<endl;
            found = true;
            break;
        }
    }
    
    if(!found){
        cout<<"NO PASSWORD saved with this USERNAME...."<<endl;
    }

    cout<<"ENTER [1 = HOME/2 = EXIT].."<<endl;
    cin>>value;
    if(value == 1){
        passmanage::menu();
    }else if (value == 2)
    {
        system("cls");
        cout<<"EXITING......"<<endl;
    }
    
}
void passmanage::chk_user(){
    system("cls");
    string pass_val;
    int value;
    cout<<"Enter PASSWORD: ";
    cin>>pass_val;
    bool found = false;
    for(int i=0;i<100;i++){
        if(password[i] == pass_val){
            cout<<"USERNAME: "<<username[i]<<endl;
            cout<<"PLATFORM: "<<platform[i]<<endl;
            found = true;
            break;
        }
    }
    
    if(!found){
        cout<<"NO USERNAME saved with this PASSWORD...."<<endl;
    }
    cout<<"ENTER [1 = HOME/2 = EXIT].."<<endl;
    cin>>value;
    if(value == 1){
        passmanage::menu();
    }else if (value == 2)
    {
        system("cls");
        cout<<"EXITING......"<<endl;
    }
    
}
void passmanage::upd_pass(){
    system("cls");
    int value;
    string user_val,pass_val;
    string new_pass;
    cout<<"Enter USERNAME: ";
    cin>>user_val;
    cout<<"Enter PASSWORD: ";
    cin>>pass_val;
    bool found = false;
    for(int i=0;i<100;i++){
        if(username[i] == user_val && password[i] == pass_val){
            cout<<"NEW PASSWORD: ";
            cin>>new_pass;
            found = true;
            password[i] = new_pass;
            break;
        }
    }
    if(!found){
        cout<<"NO USERNAME & PASSWORD are saved with these...."<<endl;
    }
    cout<<"PASSWORD successfully updated..."<<endl;
    cout<<"ENTER [1 = HOME/2 = EXIT].."<<endl;
    cin>>value;
    if(value == 1){
        passmanage::menu();
    }else if (value == 2)
    {
        system("cls");
        cout<<"EXITING......"<<endl;
    }

}
void passmanage::upd_user(){
    system("cls");
    int value;
    string user_val,pass_val;
    string new_user;
    cout<<"Enter USERNAME: ";
    cin>>user_val;
    cout<<"Enter PASSWORD: ";
    cin>>pass_val;
    bool found = false;
    for(int i=0;i<100;i++){
        if(username[i] == user_val && password[i] == pass_val){
            cout<<"NEW USERNAME: ";
            cin>>new_user;
            username[i] = new_user;
            found = true;
            break;
        }
    }
    if(!found){
        cout<<"NO USERNAME & PASSWORD are saved with these...."<<endl;
    }
    cout<<"USERNAME successfully updated..."<<endl;
    cout<<"ENTER [1 = HOME/2 = EXIT].."<<endl;
    cin>>value;
    if(value == 1){
        passmanage::menu();
    }else if (value == 2)
    {
        system("cls");
        cout<<"EXITING......"<<endl;
    }
    
}
void passmanage::gene_pass(){
    system("cls");
    int length;
    string des;
    string character = 
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "abcdefghijklmnopqrstuvwxyz"
    "1234567890"
    "!@#$%^&*";
    
    cout<<"Enter Password length: ";
    cin>>length;
    
    srand(time(0));
    string pass = "";
    for(int i=0;i<length;i++){
        int randomIndex = rand()% character.length();
        pass += character[randomIndex];
    }
    cout<<"GENERATED password: "<<pass<<endl;
    cout<<"BACK HOME[yes/no]: ";
    cin>>des;
    if(des=="yes"){
        passmanage::menu();
    }else{
        cout<<"Exiting....."<<endl;
    }

}

int main(){
    passmanage user;
    user.menu();
    return 0;
}