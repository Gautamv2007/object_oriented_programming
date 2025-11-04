#include <iostream>
using namespace std;

class User{
private:
    string FirstName;
    string LastName;
    int Age;
    string Email;
public:
    User(string firstname, string lastname, int age, string email){
        FirstName = firstname;
        LastName = lastname;
        Age = age;
        Email = email;
    }

};

int main(void){
    User user1 = User("Gautam", "V", 19, "gautam@mail.com");
    User user2("Tom", "Leighton", 55, "tom@mail.com");
}