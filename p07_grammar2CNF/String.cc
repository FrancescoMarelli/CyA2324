// Copyright (C) 2023 Francesco Marelli
// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: Algoritmo de Construcción de Subconjuntos
// Autor: Francesco Marelli
// Correo: alu0101161730@ull.edu.es
// Fecha: 22/10/2023
#include "String.h"
/**
 * @brief Construct a new String:: String object
 * 
 * @param line 
 */
String::String(const std::string& line) {
    for (int i = 0; i < line.size(); ++i)
    if (!std::iscntrl(line[i]))
        string_.push_back(Symbol(std::string(1, line[i])));
    size_ = string_.size();
}


/**
 * @brief Construct a new String:: String object
 * 
 * @param string 
 */
String::String(const String& string) {
    for (int i = 0; i < string.size_; ++i) {
        string_.push_back(string.getSymbol(i));
    }
    size_ = string.size_;
}



/**
 * @brief 
 * 
 * @param string 
 */
void String::setSymbol(std::vector<Symbol> string) {
    for (int i = 0; i < string.size(); ++i) {
        string_[i] = string[i];
    }
}


/**
 * @brief 
 * 
 * @param os 
 */
void String::write(std::ostream& os) const {
    for (int i = 0; i < size_; ++i) {
        os << string_[i].getSymbol();
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
    for (int i = 0; i < string.size_; ++i) {
        os << string.getSymbol(i);
    }
    return os;
}


/**
 * @brief 
 * 
 * @param is 
 * @param string 
 * @return std::istream& 
 */
std::istream &operator>>(std::istream &is, String &string) {
    std::string line;
    is >> line;
    string = String(line);
    return is;
}


/**
 * @brief 
 * 
 * @param alphabet 
 * @return true 
 * @return false 
 */
bool String::belongsToAlphabet(Alphabet alphabet) {
    // comprueba que string este en alphabet
    std::set<Symbol> alphabet_ = alphabet.getAlphabet();
    for (int i = 0; i < getSymbol().size(); ++i) {
        if (alphabet_.find(string_[i]) == alphabet_.end() || string_[i] != Symbol(kEpsilon)) {
            return true;
        }
    }
    return false;
}


/**
 * @brief 
 * 
 * @param other 
 * @return true 
 * @return false 
 */
bool String::operator<(const String& other) const {
    if (size_ < other.size_) {
        return true;
    }
    if (size_ > other.size_) {
        return false;
    }
    for (int i = 0; i < size_; ++i) {
        if (string_[i] < other.string_[i]) {
            return true;
        } else if (string_[i].getSymbol() > other.string_[i].getSymbol()) {
            return false;
        }
    }
    return false;
}


/**
 * @brief 
 * 
 * @param pos 
 * @param newSymbol 
 */
void String::replaceSymbol(int pos, Symbol newSymbol) {
  for (int i = 0; i < string_.size(); i++) {
    if (i == pos) {
      string_[i] = newSymbol;
    }
  }
}


/**
 * @brief 
 * 
 * @param other 
 * @return true 
 * @return false 
 */
bool String::operator==(const String& other) const {
    if (size_ != other.size_) {
        return false;
    }
    for (int i = 0; i < size_; ++i) {
        if (string_[i] != other.string_[i]) {
            return false;
        }
    }
    return true;
}
