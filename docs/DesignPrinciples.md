https://bootcamp.uxdesign.cc/software-design-principles-every-developers-should-know-23d24735518e
https://blog.cleancoder.com/uncle-bob/2014/05/08/SingleReponsibilityPrinciple.html

- “Encapsulate what varies”
- “Favor composition”
- “Program to interfaces”
- “Loose coupling”
- DRY
- KISS (TDD?)
- SOLID principles

# DRY - Don't repeat yourself
-> extract multiple occurances from lowest scope possible

# S. O. L. I. D.

## SRP - Single Responsibility Principle
"A class or module should have only one responsibility or reason to change."


## Open-Closed Principle
"Our design should be open for extension but closed for modifications"
-> working class considered locked!
Solution to add new implementation: 
- We extend the existing functionality to a new class and add the implementations there
- Use composition to accept new behaviours

## Liskov Substitution Principle
Square "is a" Rectangle; 
Derived must be replaceable by/have everything Base has; Derived must **extend** Base!
ToDo: Create classes independend, then extract similarities to a base class.
Square is Base of Rectangle...

favor "has a" (-> composition) over "is a" (inheritance aka. "inherits to")

Example: Java
ClassA classA = new ClassA();
classA.doSomething();  // should work fine
ClassA = new ClassB();
classA.doSomething();  // should work fine

## Interface Segregation Principle
"Is client using all methods?"

## Dependency Inversion Principle
"Top level modules(classes?) should not depend on low level ones"