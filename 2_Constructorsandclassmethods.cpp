#include <iostream>
#include <list>
using namespace std;

class YouTubeChannel{//The variables in a class are private by default
public:
    string Name;
    string OwnerName;
    int SubscribersCount;
    list<string> PublishedVideoTitles;

    YouTubeChannel(string name, string ownername){//The constructor name should be the same as the class name
        Name = name;
        OwnerName = ownername;
        SubscribersCount = 0;
    }

    void GetInfo(){//This is a class method to print the details
        cout << "Name: " << Name << endl;
        cout << "OwnerName: " << OwnerName << endl;
        cout << "SusbcribersCount: " << SubscribersCount << endl;
        cout << "Videos:" << endl;
        for(string s:PublishedVideoTitles){
            cout << s << endl;
        }
    }
};

int main(void){
    YouTubeChannel ytChannel("Coding", "Gautam");
    ytChannel.PublishedVideoTitles.push_back("C++ for beginners");
    ytChannel.PublishedVideoTitles.push_back("HTML & CSS for beginners");
    ytChannel.GetInfo();

}