// Copyright (C) 2023 Francesco Marelli
// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Cadenas y Alfabetos
// Autor: Francesco Marelli
// Correo: alu0101161730@ull.edu.es
// Fecha: 22/09/2023
#include "String.h"


/**
 * @brief Construct a new String:: String object
 * 
 * @param line 
 */
String::String(const std::string& line) {
    for(int i = 0; i < line.size(); ++i) {
        string_.push_back(Symbol(std::string(1,line[i])));
    }
    size_ = string_.size();
}

/**
 * @brief Construct a new String:: String object
 * 
 * @param string 
 */
String::String(const String& string){
    for(int i = 0; i < string.size_; ++i) {
        string_.push_back(string.getSymbol(i));
    }
    size_ = string_.size();
}



/**
 * @brief 
 * 
 * @param string 
 */
void String::setSymbol(std::vector<Symbol> string) {
    for(int i = 0; i < string.size(); ++i) {
        string_[i] = string[i];
    }
}


/**
 * @brief 
 * 
 * @param os 
 * @param string 
 * @return std::ostream& 
 */
std::ostream &operator<<(std::ostream &os, const String &string) {
    for(auto i = 0; i < string.size_; ++i) {
        os << string.getSymbol(i);
    }
    return os;
}


bool String::checkString(String string, Alphabet alphabet) {
    std::set<Symbol> alphabet_ = alphabet.getAlphabet();

    for(int i = 0; i < string.size_; ++i) {
       bool found = false;
       for (auto it = alphabet_.begin(); it != alphabet_.end(); ++it) {
           if (string.getSymbol(i) == *it) {
               found = true;
               break;
           }
       }
       if (!found) {
           return false;
       }
    }
    return true;
}

/**
 * @brief 
 * 
 * @return Alphabet 
 */
std::set<Symbol> String::extractAlphabet() {
    std::set<Symbol> alphabet;
    if (size() == 0) {
        return alphabet;
    }
    for(const Symbol& symbol : string_) {
        alphabet.insert(symbol);
    }
    return alphabet;
}


unsigned String::length() const {
    if (size_ == 0) {
        return 0;
    } 
    // Si contiene la cadena vacia es 0 
    if (string_[0] == Symbol("&")) {
        return 0;
    }
    else return size_ - 1 - (string_[size_ - 1] == Symbol("\0"));
}

String String::inverse(String string, Alphabet alphabet) {
    std::set<Symbol> alphabet_ = alphabet.getAlphabet();
    std::vector<Symbol> inverse;
    if (checkString(string, alphabet)) {
        for(int i = string.size_ - 1; i >= 0; --i) {
            inverse.push_back(string.getSymbol(i));
        }
        return String(inverse);
    } else {
        std::cout << "La cadena no pertenece al alfabeto" << std::endl;
        return String("&");
    }
}