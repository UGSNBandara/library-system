#include <iostream>
#include <string>
using namespace std;

//this class for handle all users basic details
//3 types of user in this system 1) admin users; 2) Registedred users 3) unregistered users

class userC{
    private:
        string name;
        string adr;
    public:
        userC();
        userC(string n, string n2, string a); //overloaded constructor
        userC(userC &arg); //copy constructor 
        ~userC();
        void modify(string n, string n2, string a); //to modyfy after created
        void printd();
    protected:
        string nic;
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

void userC::printd(){
    cout<<"Name : "<<name<<endl<<"NIC : "<<nic<<endl<<"Address : "<<adr<<endl;
}

//Admin user Class :: inharited from userC class

class admuser : public userC {
private:
    string lib_id;
    int lv;
    //super Admin : 1
    //Library manager : 2
    //Librarian : 3
    void idgenarate();
    void printallLevel();
    void printlevel();

public:
    admuser();
    ~admuser();
    admuser(string name, string nic, string addr, int level);
    admuser(admuser &arg);
    void createAcc();
    void printcard();   
};

admuser::admuser(){
    lib_id = "";
    lv = 0;
}

admuser::~admuser(){
    //destructor 
}

admuser::admuser(string name, string nic, string addr, int level):userC(name,nic,addr){
    idgenarate();
    lv = level;
}

admuser::admuser(admuser &arg):userC(arg)
{
    lv = arg.lv;
    lib_id = arg.lib_id;
}

void admuser::idgenarate(){
    lib_id = "A"+to_string(lv)+nic;
}

void admuser::createAcc(){
    string name;
    string nic;
    string addr;
    cout<<"\tWelcom to Library system"<<"Please enter your details to sing in to the system as an Admin User : ";
    cout<<endl<<"Name : ";
    cin.ignore();
    getline(cin, name);

    cout<<"NIC : ";
    getline(cin, nic);

    cout<<"Address : ";
    getline(cin, addr);

    cout<<"Select the Level :";
    printallLevel();
    cout<<" : ";
    cin>>lv;
    
    modify(name,nic,addr);
    idgenarate();
}

void admuser::printallLevel(){
    cout<<endl<<"1 : Super Admin"<<endl<<"2 : Library Manager"<<endl<<"3 : Librarian"<<endl;
}

void admuser::printcard(){
    cout<<endl<<"\t\tAccount details "<<endl;
    printd();
    cout<<"Accout Type : "<<"Admin user"<<endl<<"Level : ";
    printlevel();
    cout<<endl<<"User ID : "<<lib_id<<endl;
}

void admuser::printlevel(){
    if(lv == 1){
        cout<<"Super Admin";}
    else if(lv == 2){
        cout<<"Library Manager";
    }
    else{
        cout<<"Librarian";
    }

}

//Class for registered user:
class reguser : public userC
{   private:
    string lib_id;
    void genarateid();
    
    public:
        reguser();
        ~reguser();
        reguser(string name, string nic, string adr);
        reguser(reguser &arg);
        void createacc();
        void printcard();

    protected:
};

reguser::reguser(){
    lib_id = "";
}

reguser::~reguser(){
    //destructor
}

reguser::reguser(string name, string nic, string adr):userC(name, nic, adr){
    genarateid();
}

reguser::reguser(reguser &arg):userC(arg){
    lib_id = arg.lib_id;
} 

void reguser::createacc(){
    string name;
    string nic;
    string addr;
    cout<<"\tWelcom to Library system"<<"Please enter your details to sing in to the system as an Registered user : ";
    cout<<endl<<"Name : ";
    cin.ignore();
    getline(cin, name);

    cout<<"NIC : ";
    getline(cin, nic);

    cout<<"Address : ";
    getline(cin, addr);

    modify(name,nic,addr);
    genarateid();
}

void reguser::printcard(){

    cout<<endl<<"\t\tAccount details "<<endl;
    printd();
    cout<<"Accout Type : "<<"Regustered user";
    
    cout<<endl<<"User ID : "<<lib_id<<endl;
}

void reguser::genarateid(){
    lib_id = "RU" + nic;
}


//admin signin
void adm_signin(){
    cout<<"Hello admins";
}

//Reg usere signin
void reg_signin(){
    cout<<"Hello Useres";
}

//loging menu
void login(){
    cout<<"Hello";
}

//signgin menu 
void signin(){
    int op1;
    cout<<endl<<"\t\t\tSignin Menu"<<endl<<"1 : Library Admin\n2 : Library User"<<endl;

    while(1)
    {
    try{    
    cout<<" : ";
    cin>>op1;
    if ((op1 != 1)&&(op1 != 2)){
        throw(op1);
    }
    else{break;}
    }
    catch(int e){
        continue;}
    }
    if(op1==1)adm_signin();
    else reg_signin();
    
}

//Function for the Menu
void menu(){
    int op1;
    cout<<"\t\t\t Library Management System"<<endl;
    cout<<"1 : Login\n2 : Signin\n3 : Visit"<<endl;

    while(1)
    {
    try{    
    cout<<" : ";
    cin>>op1;
    if ((op1 != 1)&&(op1 != 2)&&(op1!=3)){
        throw(op1);
    }
    else{break;}
    }
    catch(int e){
        continue;}
    }

    if(op1==1)login();
    else if(op1==2)signin();

}


//start of the main function

int main(){
    menu();
    return 0;
}