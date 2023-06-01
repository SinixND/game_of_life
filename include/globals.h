#ifndef GLOBALS_H
#define GLOBALS_H

#include "raylib.h"
#include "screens.h"

//// Singleton Class (one object max)
////---------------------------------
//#include <mutex>

//class Singleton {
//public:
  //Singleton(Singleton const&) = delete;
  //Singleton& operator=(Singleton const&) = delete;
  //~Singleton() {}
  //// Set value has to be thread-safe.
  //void set_value(int value)
  //{
    //std::lock_guard<std::mutex> lock(m_mutex);
    //m_value = value;
  //}
  //// We don't want get value to be thread-safe in our case.
  //int get_value() const { return m_value; }
  //static Singleton* get_instance()
  //{
    //// Static local variable initialization is thread-safe
    //// and will be initialized only once.
    //static Singleton instance{};
    //return &instance;
  //}

//private:
  //explicit Singleton() : m_value{0} {}
  //std::mutex m_mutex;
  //int m_value;
//};
////---------------------------------
///**/
//// (Alternative) Singleton Class
////---------------------------------
//class Singleton{
  //private:
   
  //// member variables
  //string name, loves;
     
  //static Singleton*
         
  //// static pointer which will points
  ////to the instance of this class
  //instancePtr;
   
  //// Default constructor
  //Singleton()
  //{
  //}
   
  //public:
   
  //// deleting copy constructor
  //Singleton(const Singleton& obj)
    //= delete;
 
  ///*
    //getInstance() is a static method that returns an
    //instance when it is invoked. It returns the same
    //instance if it is invoked more than once as an instance
    //of Singleton class is already created. It is static
    //because we have to invoke this method without any object
    //of Singleton class and static method can be invoked
    //without object of class
 
    //As constructor is private so we cannot create object of
    //Singleton class without a static method as they can be
    //called without objects. We have to create an instance of
    //this Singleton class by using getInstance() method.
  //*/
  //static Singleton* getInstance()
  //{
    //// If there is no instance of class
    //// then we can create an instance.
    //if (instancePtr == NULL)
    //{
      //// We can access private members
      //// within the class.
      //instancePtr = new Singleton();
       
      //// returning the instance pointer
      //return instancePtr;
    //}
    //else
    //{
      //// if instancePtr != NULL that means
      //// the class already have an instance.
      //// So, we are returning that instance
      //// and not creating new one.
      //return instancePtr;
    //}
  //}
 
  //// sets values of member variables.
  //void setValues(string name,
                 //string loves)
  //{
    //this->name = name;
    //this->loves = loves;
  //}
   
  //// prints values of member variables
  //void print()
  //{
    //cout << name << " Loves " <<
            //loves << "." << endl;
  //}
//};
 
//// initializing instancePtr with NULL
//Singleton* Singleton ::instancePtr = NULL;
////---------------------------------

// SETTINGS
// APPLICATION
extern int windowWidth;
extern int windowHeight;
extern int targetFPS;

// GUI ELEMENTS
extern int txtSmall;
extern int txtNormal;
extern Vector2 buttonBase;
extern int guiButtonBaseWidth;
extern int guiButtonBaseHeight;

// AGENT
extern int agentWidth;
extern int agentHeight; // independent height and width possible
extern int agentInnerBorderWeight;
extern bool decayingAgents;

// AGENTS / ENVIRONMENT
extern int agentGap;
extern float lifeDensity; // in %, eg. 25

// CONTROLS
extern int evolutionTime; // in ms

// GLOBALS
extern screen currentScreen;
extern bool darkMode;
extern Color BG;
extern Color FG;
extern Color FG2;
extern Color FG3;
extern Color FG4;

#endif