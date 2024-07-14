#include <iostream>

using namespace std;

//this class for handle all users basic details
//3 types of user in this system 1) admin users; 2) Registedred users 3) unregistered users

class userC{
    private:
        string name;
        string nic;
        string adr;
    public:
        userC();
        userC(string n, string n2, string a); //overloaded constructor
        userC(userC &arg); //copy constructor 
        ~userC();
        void modify(string n, string n2, string a); //to modyfy after created
                
    private:
};

//definition for the methods of userC class
userC::userC(){
    name ="";
    nic = "";
    adr = "";
}

userC::~userC(){
    //this is desructor 
}

userC::userC(string n, string n2, string a){
    name = n;
    nic = n2;
    adr = a;
}

userC::userC(userC &arg){
    name = arg.name;
    nic = arg.nic;
    adr = arg.adr;
}

void userC::modify(string n, string n2, string a){
    name = n;
    nic = n2;
    adr = a;
}




//start of the main function

int main(){
    userC user("sulitha", "20030119", "chnabay");
    cout<<"hello";

    return 0;
}