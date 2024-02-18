/***********************************************************************
// Version 1.0
// Date: feb 18 2024
// Author: alex mwnaiki
***********************************************************************/

#include "Guitar.h"

// GuitarStr class implementation

GuitarStr::GuitarStr() {
    m_material = "";
    m_gauge = 0.0;
}

GuitarStr::GuitarStr(const char* material, double gauge) {
    m_material = material;
    m_gauge = gauge;
}

const char* GuitarStr::material() const {
    return m_material;
}

double GuitarStr::gauge() const {
    return m_gauge;
}

// Guitar class implementation

Guitar::Guitar() : m_numStrings(0), m_model("") {}

Guitar::Guitar(const char* model) : m_numStrings(0), m_model(model) {}

Guitar::Guitar(GuitarStr* strings, int numStrings, const char* model) : m_numStrings(numStrings), m_model(model) {
    m_strings = new GuitarStr[m_numStrings];
    for (int i = 0; i < m_numStrings; i++) {
        m_strings[i] = strings[i];
    }
}

Guitar::~Guitar() {
    delete[] m_strings;
}

void Guitar::display() const {
    std::cout << "Model: " << m_model << "\n";
    std::cout << "Number of strings: " << m_numStrings << "\n";
    std::cout << "Strings:\n";
    for (int i = 0; i < m_numStrings; i++) {
        std::cout << "String " << (i + 1) << ": Material - " << m_strings[i].material() << ", Gauge - " << m_strings[i].gauge() << "\n";
    }
}

void Guitar::deString() {
    delete[] m_strings;
    m_numStrings = 0;
    m_strings = nullptr;
}

void Guitar::reString(GuitarStr* strings, int numStrings) {
    delete[] m_strings;
    m_strings = new GuitarStr[numStrings];
    m_numStrings = numStrings;
    for (int i = 0; i < m_numStrings; i++) {
        m_strings[i] = strings[i];
    }
}

bool Guitar::strung() const {
    return m_strings != nullptr;
}

bool Guitar::changeString(const GuitarStr& newString, int stringNum) {
    if (stringNum >= 1 && stringNum <= m_numStrings) {
        m_strings[stringNum - 1] = newString;
        return true;
    }
    return false;
}

bool Guitar::matchGauge(double targetGauge) const {
    for (int i = 0; i < m_numStrings; i++) {
        if (m_strings[i].gauge() == targetGauge) {
            return true;
        }
    }
    return false;
}
