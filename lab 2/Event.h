#ifndef EVENT_H
#define EVENT_H
#include <string>
#include <vector>
#include <QString>
#endif // EVENT_H

class Event
{
private:
  std::string name;
  int numres;
  double chance;
  double frequency;
   int num_exp;
public:

Event(){
    frequency=0;
    numres=0;
}


  Event(std::string NewName, const double& NewChance)
  {

    name = NewName;
    frequency=0;
    numres=0;
    chance = NewChance;
     num_exp=0;
  }

  std::string GetName() const
  {
    return name;
  }

  int GetNumberOfResults()const
  {
    return numres;
  }

  double Get_frequency(){
      return frequency;
  }

  double GetChance() const
  {
    return chance;
  }
  void setChance(double c){
      chance=c;
  }
  void intrusion(){

      numres++;
      frequency=numres;
      frequency/=num_exp;
  }
  void set_num_exp(int num){
      num_exp+=num;
  }
};




class demonstration{
private:


    std::string Name;

    int number_of_tests;

    std::vector<std::string> experement;
public:
 std::vector<Event> events;

    demonstration(){

        number_of_tests=1;
        events={};
        number_of_tests=1;
    }

    demonstration(std::string a){
        Name=a;
        number_of_tests=1;
        events={};
    }

    void Name_enter(std::string g){
        Name=g;
    }
    std::string Name_show(){
        return Name;
    }

    void add_event(Event a){
        events.push_back(a);
        double v=0;
          int N=events.size();
        for(int i=0;i<N;i++){
            v+=events[i].GetChance();
        }
        if(v>100.0){


            for(int i=0;i<N;i++){
                events[i].setChance(events[i].GetChance()/v*100.0);
            }
        }
    }

    void remove_event(Event a){
        int N=events.size();
        for(int i=0;i<N;i++){
            if(events[i].GetName()==a.GetName()){
                for(int j=i;j<N-1;j++){
                    events[j]=events[j+1];
                }
                events.pop_back();
            }
        }

    }

    void remove_all_event(){
        int N=events.size();
        for(int i=0;i<N;i++){
            events.pop_back();
        }

    }
    int num_events(){
       return events.size();
    }

    void set_num(int a){
        number_of_tests=a;
    }


    void start_demonstration(){


        double v=0;
          int N=events.size();
        for(int i=0;i<N;i++){\
            events[i].set_num_exp(number_of_tests);
            v+=events[i].GetChance();
        }
        if(v<100.0){


            for(int i=0;i<N;i++){
                events[i].setChance(events[i].GetChance()/v*100.0);
            }
        }
        int num;
        int probalities;
        for(int i=0;i<number_of_tests;i++){
            probalities=0;
            num=rand()%100;
            for(int j=0;j<N;j++){
                probalities+=events[j].GetChance();
                if(probalities>num){
                    experement.push_back(events[j].GetName());
                    events[j].intrusion();
                    break;
                }
            }

        }
    }
    void end_demonstration(){
        experement={};
    }
    std::vector<std::string> getExperment(){
        return experement;
    }
};
