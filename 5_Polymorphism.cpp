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
    int ContentQuality;
public:
    YouTubeChannel(string name, string ownername){ // The constructor name should be the same as the class name
        Name = name;
        OwnerName = ownername;
        SubscribersCount = 0;
        ContentQuality = 0;
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
    void CheckAnalytics(){
        if (ContentQuality < 5){
            cout << Name << " has bad quality content." << endl;
        }
        else cout << Name << " has great content." << endl; 
    }
};

//We are going to make another class called cooking channel. Instead of copying the variables from the above class. We can inherit it.
class CookingYoutubeChannel : public YouTubeChannel{//CookingYoutubeChannel is the derived class
public:
    CookingYoutubeChannel(string name, string ownername) : YouTubeChannel(name, ownername){

    }
    void Practice(){
        cout << OwnerName << " is practicing cooking, learning new recipes, experimenting with spices..." << endl;
        ContentQuality++;
    }
};


class SingerYoutubeChannel:public YouTubeChannel {
public:
    SingerYoutubeChannel(string name, string ownername): YouTubeChannel(name, ownername){

    }
    void Practice(){
        cout << OwnerName << " is taking singing classes, learning new songs, learning how to dance..." << endl;
        ContentQuality++;
    }
};

int main(void){
    CookingYoutubeChannel cookingYtChannel("Amy's Kitchen", "Amy");
    SingerYoutubeChannel singersYtChannel("JohnSings", "John");

    cookingYtChannel.Practice();
    singersYtChannel.Practice();
    singersYtChannel.Practice();
    singersYtChannel.Practice();
    singersYtChannel.Practice();
    singersYtChannel.Practice();
    
    //Here we are using pointers of base class and storing the address of the derived class in it.
    YouTubeChannel *yt1 = &cookingYtChannel;
    YouTubeChannel *yt2 = &singersYtChannel;


    yt1->CheckAnalytics();
    yt2->CheckAnalytics();

}