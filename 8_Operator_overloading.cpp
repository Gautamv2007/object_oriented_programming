#include <iostream>
#include <string>
#include <list>
using namespace std;

class YoutubeChannel{
    string Name;
    int SubscribersCount;
public:
    YoutubeChannel(string name, int subsciberscount){
        Name = name;
        SubscribersCount = subsciberscount;
    }

    friend ostream& operator<<(ostream& COUT, YoutubeChannel& ytChannel){
        COUT << "Name: " << ytChannel.Name << endl;
        COUT << "Subscribers: " << ytChannel.SubscribersCount << endl;
        return COUT; // We need to return the "COUT" because this function returns ostream
    }

    bool operator==(const YoutubeChannel& ytChannel) const{
        return Name == ytChannel.Name;
    }
};

class MyCollection{
    list<YoutubeChannel> myChannels;
public:
    void operator+=(YoutubeChannel& yt1){
        this->myChannels.push_back(yt1);//"this" refers to the existing class myCollection present before the += symbol
        //myCollection is available automatically because it is a member function
    }

    void operator-=(YoutubeChannel& yt1){
        this->myChannels.remove(yt1);
    }   
    friend ostream& operator<<(ostream& COUT, MyCollection& mycollection){
        for(YoutubeChannel yt:mycollection.myChannels){
            COUT << yt << endl;
        }
        return COUT;
    }
};

int main(void){
    YoutubeChannel yt1 = YoutubeChannel("Coding", 75000);
    YoutubeChannel yt2 = YoutubeChannel("Second Channel", 60000);
    cout << yt1 << yt2;
    //Since operator overloading is a function we can also call it like this
    // operator<<(cout, yt2);

    MyCollection myCollection;
    myCollection += yt1; //We are using this function to append each YoutubeChannel class into one single collection
    myCollection += yt2;
    myCollection += yt2;
    myCollection -= yt2;
    cout << myCollection;
}