#include <iostream>
#include <list>
using namespace std;

//Encapsulation says that the variables must be private
class YouTubeChannel{//The variables in a class are private by default
private:
    string Name;
    string OwnerName;
    int SubscribersCount;
    list<string> PublishedVideoTitles;
public:
    YouTubeChannel(string name, string ownername){ // The constructor name should be the same as the class name
        Name = name;
        OwnerName = ownername;
        SubscribersCount = 0;
    }
    void GetInfo(){
        cout << "Name: " << Name << endl;
        cout << "OwnerName: " << OwnerName << endl;
        cout << "SusbcribersCount: " << SubscribersCount << endl;
        cout << "Videos:" << endl;
        for(string s:PublishedVideoTitles){
            cout << s << endl;
        }
    }

    void Subscribe(){
        SubscribersCount++;
    }
    void Unsubscribe(){
        if (SubscribersCount > 0) 
        SubscribersCount--;
    }
    void PublishVideos(string video){
        PublishedVideoTitles.push_back(video);
    }
};

int main(void){
    YouTubeChannel ytChannel("Coding", "Gautam");
    ytChannel.PublishVideos("C++ for beginners");
    ytChannel.PublishVideos("HTML & CSS for beginners");
    ytChannel.Subscribe();
    ytChannel.Unsubscribe();
    ytChannel.GetInfo();

}