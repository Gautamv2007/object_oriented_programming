#include <iostream>
#include <list>
using namespace std;

class YouTubeChannel{//The variables in a class are private by default
public:
    string Name;
    string OwnerName;
    int SubscribersCount;
    list<string> PublishedVideoTitles;
};

int main(void){
    YouTubeChannel ytChannel;
    ytChannel.Name = "Coding";
    ytChannel.OwnerName = "Gautam";
    ytChannel.SubscribersCount = 12000;
    ytChannel.PublishedVideoTitles = {"C++ for beginners video 1", "HTML & CSS video 1"};

    cout << "Name: " << ytChannel.Name << endl;
    cout << "OwnerName: " << ytChannel.OwnerName << endl;
    cout << "SusbcribersCount: " << ytChannel.SubscribersCount << endl;
    cout << "Videos:" << endl;
    for(string s:ytChannel.PublishedVideoTitles){
        cout << s << endl;
    } 
}