#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>

using namespace std;

class plug{
private:
  map <char, char> connect;

public:
  plug(string plugConnects = ""){
    for (char c = 'A' ; c <= 'Z' ; c++){
      connect[c] = c;
    }

    for (unsigned i = 0 ; i < plugConnects.size() ; i+=3){
      connect[plugConnects[i]] = plugConnects[i+1];
      connect[plugConnects[i+1]] = plugConnects[i];
    }
  }

  char operator [](char c){
    return connect[c];
  }
};

class rotor{
private:
  string name;
  vector <unsigned> connect;
  unsigned turnover;

public:
  rotor(string _name = "", string _settings = "", char _turnover = 'Z'){
    name = _name;
    turnover = _turnover - 'A';
    for (unsigned i = 0 ; i < 26 ; i++){
      connect.push_back(_settings[i] - 'A');
    }
  }

  unsigned operator [](unsigned n){
    return connect[n];
  }

  void turn(int nr){
    rotate(connect.begin(), connect.begin() + nr, connect.end());
  }

  string get_name(){
    return name;
  }

  unsigned get_turnover(){
    return turnover;
  }
};

class enigma{
public:
  rotor rotors[3];
  plug plugs;

  enigma(rotor _rot1, rotor _rot2, rotor _rot3, unsigned _pos1, unsigned _pos2, unsigned _pos3, plug _plug){
    rotors[0] = _rot1;
    rotors[0].turn(_pos1-1);

    rotors[1] = _rot2;
    rotors[0].turn(_pos2-1);

    rotors[2] = _rot3;
    rotors[0].turn(_pos3-1);

    plugs = _plug;
  }

  void turn_rotor(unsigned i){
    rotors[i].turn(1);
  }
};

int main(){
  plug p1("PO ML IU KJ NH YT GB VF RE DC");
  rotor rotors[5] = { {"I"  , "EKMFLGDQVZNTOWYHXUSPAIBRCJ", 'R'},
                      {"II" , "AJDKSIRUXBLHWTMCQGZNPYFVOE", 'F'},
                      {"III", "BDFHJLCPRTXVZNYEIWGAKMUSQO", 'W'},
                      {"IV" , "ESOVPZJAYQUIRHXLNFTGKDCMWB", 'K'},
                      {"V"  , "VZBRGITYUPSDNHLXAWMJQOFECK", 'A'} };
  rotor reflector = {""};

  enigma enigga = {rotors[0], rotors[1], rotors[2], 1, 1, 1, p1};
}
