#ifndef FULL_TIME_H
#define FULL_TIME_H

#include <cstring>
#include "Employee.h"

using namespace std;

class Full_time : public Employee{
    private:
        char* position;
        int seniority; // The length of working years. A longer working
                       // years yield a higher salary in general. Eg, 
                       // seniority = 5 means working for 5 years.
        double bonus;
    public:
    /*TODO:complete the member function declaration of Full_time class
      based on the given functions on the web page.
    */
    Full_time(const char*, double, const char*, int, double);
    virtual ~Full_time() override;

    string get_position() const;
    int get_seniority() const;
    double get_bonus() const;

    virtual double get_salary() const override;
    virtual void print() const override;
};
#endif