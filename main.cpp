#include <iostream>
#include <algorithm>
#include <list>
using namespace std;
class Observer
{
public:
    virtual void update(string status) = 0;
};
class FacebookUserSubject
{
public:
    virtual void registerObserver(Observer *o) = 0;
    virtual void removeObserver(Observer *o) = 0;
    virtual void notifyObserver() = 0;
};
class BeautifulGirl : public FacebookUserSubject
{
private:
    list<Observer *> observers;
    string status;

public:
    void setStatus(string herStatus)
    {
        this->status = herStatus;
        notifyObserver();
    }
    void registerObserver(Observer *o)
    {
        observers.push_back(o);
        cout << endl
             << "--> System notification: 1 person just follow you!. You have: " << observers.size() << " follower" << endl;
    }
    void removeObserver(Observer *o)
    {
        observers.remove(o);
        cout << endl
             << "--> System notification: 1 person just UN-follow you!. You have: " << observers.size() << " follower" << endl;
    }
    void notifyObserver()
    {
        for (Observer *ob : observers)
        {
            ob->update(status);
        }
    }
};
class Follower : public Observer
{
private:
    string userName;

public:
    Follower(string userName)
    {
        this->userName = userName;
    }
    void update(string herStatus)
    {
        cout << "Hello " << userName << "! You have a message from your crush: " << herStatus << endl;
    }
};
int main()
{
    BeautifulGirl *user = new BeautifulGirl();
    Observer *followerA = new Follower("Follower 1");
    Observer *followerB = new Follower("Follower 2");
    Observer *followerC = new Follower("Follower 3");
    user->registerObserver(followerA);
    user->setStatus("I'm hungry");
    user->registerObserver(followerB);
    user->setStatus("I'm boring");
    user->registerObserver(followerC);
    user->setStatus("I have a boyfriend");
    user->removeObserver(followerB);
    user->setStatus("I will go to Vietnam");
    user->setStatus("I I just broke up with him");
    user->registerObserver(followerB);
    user->setStatus("I have been lived in here for 1 day, the best country that I know");
    return 0;
}