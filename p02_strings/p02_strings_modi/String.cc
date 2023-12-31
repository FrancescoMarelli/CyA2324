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
 * through a std::string
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
 * through a String(vector of symbols)
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
 * @brief Setter for the string
 * 
 * @param string 
 */
void String::setSymbol(std::vector<Symbol> string) {
    for (int i = 0; i < string.size(); ++i) {
        string_[i] = string[i];
    }
}


/**
 * @brief Write method for String
 * 
 * @param os 
 */
void String::write(std::ostream& os) const {
    for (int i = 0; i < size_; ++i) {
        os << string_[i].getSymbol();
    }
    os << std::endl;
}

/**
 * @brief Extractor operator for String
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
 * @brief Method that check if a string is in an alphabet
 * 
 * @param alphabet 
 * @return true 
 * @return false 
 */
bool String::checkString(Alphabet alphabet) {
    // comprueba que string este en alphabet
    std::set<Symbol> alpha = alphabet.getAlphabet();
    for (int i = 0; i < size_; ++i) {
        if (alpha.find(string_[i]) == alpha.end()) {
            return false;
        }
    }
    return true;
}


/**
 * @brief Method of function 1 that build the alphabet
 * from a string 
 * 
 * @return Alphabet 
 */
std::set<Symbol> String::extractAlphabet() {
    std::set<Symbol> alphabet;
    if (size() == 0) {
        return alphabet;
    }
    if (string_[0] == Symbol(kEpsilon)) {
        return alphabet;
    }
    for (const Symbol& symbol : string_) {
        if (symbol != Symbol(kEpsilon)) {
            alphabet.insert(symbol);
        }
    }
    return alphabet;
}


/**
 * @brief Method of function 2 that extract the length of a string
 * 
 * @return unsigned 
 */
unsigned String::extractLength() const {
    // Si contiene la cadena vacia es 0
    if (string_[0] == Symbol(kEpsilon)) {
        return 0;
    } else {
        return size_  - (string_[size_ - 1] == Symbol("\0"));
    }
}


/**
 * @brief  Method of function 3 that invert a string
 * 
 * @param string 
 * @param alphabet 
 * @return String 
 */
String String::inverse(String string, Alphabet alphabet) {
  std::set<Symbol> alphabet_ = alphabet.getAlphabet();
  std::vector<Symbol> inverse;
  if (checkString(alphabet)) {
    for (int i = 0; i < string.size_; ++i) {
    if (alphabet_.find(string.getSymbol(i)) != alphabet_.end()) {
      inverse.push_back(string.getSymbol(i));
    }
  }


  // Invert the string without empty symbols
  std::reverse(inverse.begin(), inverse.end());
    return String(inverse);
  } else {
    return String(kEpsilon);
  }
}

/**
 * @brief Method of function 4 that extract the prefixes of a string
 * 
 * @return std::set<String> 
 */
std::set<String> String::extractPrefixes() {
    std::set<String> prefixes;
    std::string prefix;
    for (int i = 0; i < size_; ++i) {
        prefix += string_[i].getSymbol();
        prefixes.insert(String(prefix));
    }
    return prefixes;
}


/**
 * @brief Method of function 5 that extract the suffixes of a string
 * 
 * @return std::set<String> 
 */
std::set<String> String::extractSuffixes() {
    std::set<String> suffixes;
    std::string suffix;
    for (int i = size_ - 1; i >= 0; --i) {
        suffix = string_[i].getSymbol() + suffix;
        suffixes.insert(String(suffix));
    }
    return suffixes;
}


/**
 * @brief Less Operator of string that compare two strings
 * size, and order
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
 * @brief Method that extract the substrings of a string
 * that are both prefix and suffix
 * 
 * @return std::set<String> 
 */
std::set<String> String::prefixSuffix() {
    std::set<String> prefixesString = extractPrefixes();
    std::set<String> suffixesString = extractSuffixes();
    std::set<String> substrings;
    for (const String& prefix : prefixesString) {
        if (suffixesString.find(prefix) != suffixesString.end()) {
            substrings.insert(prefix);
        }
    }
    return substrings;
}
