//////////////////////////////////////////////////////////
///Example for the decorator pattern.
/// //////////////////////////////////////////////////////

#include <iostream>

using namespace std;
class RunWay
{
public:
    virtual std::string run() = 0;
};
class DrivingWay : public RunWay
{
public:
    virtual std::string run()
    {
        return "driving...";
    }
};

class FlyingWay : public RunWay
{
public:
    virtual std::string run()
    {
        return "flying...";
    }
};


class Vehicle
{
    RunWay *run;
    virtual const std::string name() = 0;
public:
    Vehicle(){}
    ~Vehicle(){}
    void setRunWay(RunWay *iRun) {run = iRun;}
    void go(){cout << name() << " is "<< run->run()<<"\n";}
};

class Car : public Vehicle
{
   virtual const std::string name() {return "Car";}
public:
    Car(){}
    ~Car(){}
};
class Plane : public Vehicle
{
   virtual const std::string name() {return "Plane";}
   public:
    Plane(){}
    ~Plane(){}
};

int main()
{
    DrivingWay *driving = new DrivingWay();
    FlyingWay *flying = new FlyingWay();

    //car just drives
    Car* car = new Car();
    car->setRunWay(driving);
    car->go();

    //plane drives to take off
    //flies, after landing , drives again
    Plane *plane = new Plane();
    plane->setRunWay(driving);
    plane->go();
    plane->setRunWay(flying);
    plane->go();
    plane->setRunWay(driving);
    plane->go();

    return 0;
}

