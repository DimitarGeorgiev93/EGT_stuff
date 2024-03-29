

#include <iostream>
#include "ThreeDimShape.h"
#include "Square.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
#include <vector>
#include <string>
#include <stdlib.h>

void drawingFigLoop();
void freeVector(std::vector<Shape*>&);
const bool ValidateIntEntry( const int);
const bool ValidateCharEntry( const char);


int main()
{
    drawingFigLoop();

    return 0;
}

void drawingFigLoop() 
{
    int command = 0, x = 0, y = 0, pos =0;
    char drawingShape = 'a';
    std::vector<Shape*> arr;
    Shape* ptr = nullptr;
    while (true) 
    {
        std::cout << "First number - type of object ( 1 - rectangle, 2 - square, 3 - circle , 4- triangle )" << std::endl;
        std::cout << "Second number - width of the object ( 0x )" << std::endl;
        std::cout << "Third number - height of the object ( 0y ) / is ignored in circle and square" << std::endl;
        std::cout << "Fourth number  - prints X above and on the left of the object " << std::endl;
        std::cout << "Char - what charcater the object will have as a drawingChar " << std::endl;
        std::cout << "to exit - type 5, will print all created objects so far " << std::endl;

        std::cin >> command;

        if (!std::cin)
        {
            system("CLS");
            std::cout << "Invalid entry, try again " << std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        }
        else if (ValidateIntEntry(command) == false)
        {
            system("CLS");
            std::cout << "Invalid entry, try again " << std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        }

        if (command == 5) 
        {
            system("CLS");
            freeVector(arr);
            break;
        }

        std::cin >> x >> y >> pos >> drawingShape;
        if (!std::cin)
        {
            system("CLS");
            std::cout << "Invalid entry, try again " << std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        }
        else if (ValidateIntEntry(command) == false || ValidateIntEntry(x) == false || ValidateIntEntry(y) == false || ValidateIntEntry(pos) == false || 
            ValidateCharEntry(drawingShape) == false )
        {
            system("CLS");
            std::cout << "Invalid entry, try again " << std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        }
        std::cin.ignore(10000, '\n');

        switch (command)
        {
        case 1:
            ptr = new Rectangle(x, y, pos, drawingShape);
            arr.push_back(ptr);
            ptr->draw();
            std::cout << "added a Rec" << std::endl;
            ptr = nullptr;
            break;
        case 2:
            ptr = new Square(x, x, pos, drawingShape);
            arr.push_back(ptr);
            ptr->draw();
            ptr = nullptr;
            std::cout << "added a Square" << std::endl;
            break;
        case 3:
            ptr = new Circle(x, pos, drawingShape);
            arr.push_back(ptr);
            ptr->draw();
            ptr = nullptr;
            std::cout << "added a Circle" << std::endl;
            break;
        case 4:
            ptr = new Triangle(x, y, pos, drawingShape);
            arr.push_back(ptr);
            ptr->draw();
            ptr = nullptr;
            std::cout << "added a Triangle" << std::endl;
            break;
        default:
            std::cout << "nothing added, figures are 1 to 4" << std::endl;
            break;
        
        }
    }
}

void freeVector(std::vector<Shape*>& arr)
{
    int count = 1;
    for (Shape* var : arr)
    {
        std::cout << "drawing " << count++ << std::endl;
        var->draw();
        delete var;
        var = nullptr;
    }
}

const bool ValidateCharEntry(const char character)
{
    if (character < 33 || character > 126)
    {
        return false;
    }
    return true;
}

const bool ValidateIntEntry(const int number)
{
    if (number % 1 != 0)
    {
        return false;
    }
    return true;
}

