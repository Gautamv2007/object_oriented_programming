#include <iostream>
#include <list>
using namespace std;

//Encapsulation says that the variables must be private
class YouTubeChannel{//The variables in a class are private by default
private:
    string Name;
    int SubscribersCount;
    list<string> PublishedVideoTitles;
protected: 
    string OwnerName;//We are putting the ownername in protected access specifier so that it is accessible to the derived class.
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

//We are going to make another class called cooking channel. Instead of copying the variables from the above class. We can inherit it.
class CookingYoutubeChannel : public YouTubeChannel{//CookingYoutubeChannel is the derived class
public:
    CookingYoutubeChannel(string name, string ownername) : YouTubeChannel(name, ownername){

    }
    void Practice(){
        cout << OwnerName << " is practicing cooking, learning new recipes, experimenting with spices..." << endl;
    }
};

int main(void){
    CookingYoutubeChannel cookingYtChannel("Amy's Kitchen", "Amy");
    cookingYtChannel.PublishVideos("Apple Pie");
    cookingYtChannel.Subscribe();
    cookingYtChannel.Subscribe();
    cookingYtChannel.GetInfo();
    cookingYtChannel.Practice();
}