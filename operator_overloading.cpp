#include <iostream>
#include <string>
#include <list>

using namespace std;

struct YoutubeChannel{
    string Name;
    int SubscribersCount;

    //This is a struct constructor
    YoutubeChannel(string name, int subscribersCount){
        Name = name;
        SubscribersCount = subscribersCount;
    }

    bool operator==(const YoutubeChannel&channel) const{ //We should use this operator to help compare.
        return this->Name == channel.Name; //We should also use the const keyword to confirm that the argument is not going to change.
    }
};

ostream& operator<<(ostream& COUT, YoutubeChannel& ytChannel){
    COUT<<"Name: "<<ytChannel.Name<<endl;
    COUT<<"Subscribers: "<<ytChannel.SubscribersCount<<endl;
    return COUT;
}

struct MyCollection {
    list<YoutubeChannel> myChannels;

    void operator+=(YoutubeChannel& ytChannel){
        this->myChannels.push_back(ytChannel); //Refers to myCollection
    }
    
    void operator-=(YoutubeChannel& ytChannel){
        this->myChannels.remove(ytChannel); 
    }
};

ostream& operator<<(ostream& COUT, MyCollection& myCollection){
    for(YoutubeChannel ytChannel:myCollection.myChannels){
        COUT << ytChannel << endl;
    }
    return COUT;
}

int main(){
    YoutubeChannel yt1 = YoutubeChannel("Code", 75000);
    YoutubeChannel yt2 = YoutubeChannel("My second channel", 80000);
    cout << yt1;
    //operator<<(cout, yt2);//Can also use operator function like this.
    MyCollection myCollection;
    myCollection += yt1;
    myCollection += yt2;
    myCollection -= yt2;
    cout << myCollection;
    return 0;
}