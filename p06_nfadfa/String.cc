// Copyright (C) 2023 Francesco Marelli
// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 5: Implementación de un Automata finito
// Autor: Francesco Marelli
// Correo: alu0101161730@ull.edu.es
// Fecha: 12/10/2023
#include "String.h"
#include "Language.h"

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
    os << std::endl;
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
 * @return Alphabet 
 */
Alphabet String::extractAlphabet() {
    std::set<Symbol> alphabet;
    if (size() == 0) {
        return Alphabet(alphabet);
    }
    if (string_[0] == Symbol(kEpsilon)) {
        return Alphabet(alphabet);
    }
    for (const Symbol& symbol : string_) {
        if (symbol != Symbol(kEpsilon)) {
            alphabet.insert(symbol);
        }
    }
    return Alphabet(alphabet);
}


/**
 * @brief 
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
 * @brief 
 * 
 * @param string 
 * @param alphabet 
 * @return String 
 */
String String::inverse(String string, Alphabet alphabet) {
  std::set<Symbol> alphabet_ = alphabet.getAlphabet();
  std::vector<Symbol> inverse;
  if (belongsToAlphabet(alphabet)) {
    for (int i = 0; i < string.size_; ++i) {
    if (alphabet_.find(string.getSymbol(i)) != alphabet_.end()) {
      inverse.push_back(string.getSymbol(i));
    }
  }

  // Invierte el vector 'inverse' sin los simbolos vacios
  std::reverse(inverse.begin(), inverse.end());
    return String(inverse);
  } else {
    std::cout << "La cadena " << string << " no pertenece al alfabeto " << std::endl;
    return String("");
  }
}

/**
 * @brief 
 * 
 * @return Language
 */
Language String::extractPrefixes() {
    std::set<String> prefixes;
    std::string prefix;
    for (int i = 0; i < size_; ++i) {
        prefix += string_[i].getSymbol();
        prefixes.insert(String(prefix));
    }
    return Language(prefixes);
}


/**
 * @brief 
 * 
 * @return Language 
 */
Language String::extractSuffixes() {
    std::set<String> suffixes;
    std::string suffix;
    for (int i = size_ - 1; i >= 0; --i) {
        suffix = string_[i].getSymbol() + suffix;
        suffixes.insert(String(suffix));
    }
    return Language(suffixes);
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

