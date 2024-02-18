/***********************************************************************
// Version 1.0
// Date: feb 18 2024
// Author: alex mwnaiki
***********************************************************************/

#ifndef GUITAR_H
#define GUITAR_H

#include <iostream>

class GuitarStr {
public:
    GuitarStr();
    GuitarStr(const char* material, double gauge);
    const char* material() const;
    double gauge() const;

private:
    const char* m_material;
    double m_gauge;
};

class Guitar {
public:
    Guitar();
    Guitar(const char* model);
    Guitar(GuitarStr* strings, int numStrings, const char* model);
    ~Guitar();
    void display() const;
    void deString();
    void reString(GuitarStr* strings, int numStrings);
    bool strung() const;
    bool changeString(const GuitarStr& newString, int stringNum);
    bool matchGauge(double targetGauge) const;

private:
    GuitarStr* m_strings;
    int m_numStrings;
    const char* m_model;
};

#endif
