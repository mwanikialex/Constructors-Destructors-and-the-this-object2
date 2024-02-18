/***********************************************************************
// OOP244 Workshop #4 p2
//
// File  main.cpp
// Version 1.0
// Date:
// Author:
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#include "Guitar.h"

int main() {
    std::cout << "******************************\n";
    std::cout << "Empty Guitar\n";
    std::cout << "******************************\n";
    Guitar guitar1;
    guitar1.display();
    std::cout << "******************************\n\n";

    std::cout << "******************************\n";
    std::cout << "Non Empty Guitar\n";
    std::cout << "******************************\n";
    GuitarStr strings[] = {
        GuitarStr("Bronze", 0.7),
        GuitarStr("Steel", 0.9)
    };
    Guitar guitar2(strings, 2, "Les Paul");
    guitar2.display();
    std::cout << "******************************\n\n";

    std::cout << "******************************\n";
    std::cout << "Change Strings\n";
    std::cout << "******************************\n";
    GuitarStr newString("Nylon", 0.6);
    bool changed = guitar2.changeString(newString, 0);
    guitar2.display();
    if (!changed) {
        std::cout << "Unable to change string (correct)\n";
    }
    std::cout << "******************************\n\n";

    std::cout << "******************************\n";
    std::cout << "Destring and Restring\n";
    std::cout << "******************************\n";
    guitar2.deString();
    guitar2.reString(strings, 2);
    guitar2.display();
    std::cout << "Guitar is correctly destrung\n";
    std::cout << "******************************\n\n";

    std::cout << "******************************\n";
    std::cout << "Check Gauge\n";
    std::cout << "******************************\n";
    bool gaugeMatch = guitar2.matchGauge(0.8);
    if (!gaugeMatch) {
        std::cout << "Gauges don't match (correct)\n";
    }
    gaugeMatch = guitar2.matchGauge(0.7);
    if (gaugeMatch) {
        std::cout << "Gauges match (correct)\n";
    }
    std::cout << "******************************\n";

    return 0;
}