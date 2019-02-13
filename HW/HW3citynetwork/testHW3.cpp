#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;


struct city
{
    string  name;            // name of the city
    city *  next;            // pointer to the next city
    int     numberMessages;  // how many messages passed through this city
    string  message;         // message we are sending accross
};

class CityNetwork {
    private:
        // pointer to head of linked list of cities
        city* head;
    public:
        CityNetwork();
        bool isEmpty();
        /* NOTE: you will complete all the methods marked
             'TODO'. Definitions are below. Careful with the
              print statements, moodle expects the output to
              match exactly. */
        //void startup();
        void addCity(city* previous, string cityName); // TODO
        //void deleteCity(string cityName);              // TODO
        //void loadDefaultSetup();                       // TODO
        //city* searchNetwork(string cityName);          // TODO
        //void deleteEntireNetwork();                    // TODO
        //void transmitMsg(string receiver, string msg); // TODO
        //void printPath();                              // TODO
};

CityNetwork::CityNetwork() {
    /* finished! do not modify this function. */
    head = NULL;
}
bool CityNetwork::isEmpty() {
    /* finished! do not modify this function. */
    return (head == NULL);
}

// void CityNetwork::startup()
// {
//   city* newcity=new city;
//   newcity->name="TEST";
//   newcity->next=NULL;
//   newcity->numberMessages=0;
//   newcity->message="";
//   cout<<newcity->name<<endl;
//   cout<<newcity->next<<endl;
//   cout<<newcity->numberMessages<<endl;
//   cout<<&newcity<<endl;
// }

void CityNetwork::addCity(city* previous, string cityName) {
    // TODO: implement this function
    city* c =new city;
    c->name=cityName;
    c->numberMessages=0;
    c->message="";
    c->next=NULL;


    if (head==NULL)
    {

      head=c;
      cout << "adding: " << cityName << " (HEAD)" << endl;
    }
    else if(previous==NULL)
    {
      c->next=head;
      head=c;
      cout << "adding: " << cityName << " (HEAD)" << endl;

    }
    else
    {
      c->next =previous->next;
      previous->next=c;
      cout << "adding: " << cityName << " (prev: " << previous->name << ")" << endl;

    }

    // required print statements:
        //print the city name we're adding and city name we're following, e.g.

        //if adding to front of list, instead print:


}


void CityNetwork::deleteEntireNetwork() {
    // TODO: implement this function.
    city* tmp=head;
    string tstring="";
    bool flag=false;

    city*prev;
    while (tmp!=NULL)
    {
      tstring=tmp->name;

      if(tmp->name!=tstring)
      {
        prev=tmp;
        tmp=tmp->next;
      }
      else if (tmp->name==tstring and tmp==head)
      {
        head=tmp->next;
        flag=true;
        delete tmp;
        break;
      }

      else
      {
        prev->next=tmp->next;
        delete tmp;
        flag=true;
        break;
      }
    }

        if(flag==false)
        {
          cout << "City does not exist." << endl;
        }




    cout << "Deleted network" << endl;
}



int main()
{
  CityNetwork cit;
  //cit.startup();

  cit.addCity(NULL,"LA");
  cit.addCity()
}
