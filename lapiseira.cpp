#include <iostream>
#include <map>
#include <string>

using namespace std;

class grafite {
  public:
  float calibre = 0;
  string dureza = "";
  int tamanho = 0;
  
  grafite() { }
  
  grafite(grafite&) { }
  
  grafite(float calibre, string dureza, 
  int tamanho) : calibre(calibre), dureza(dureza),
  tamanho(tamanho) { }
  
  string toString() {
    return "["+
      to_string(this->calibre)+ ", " +
      this->dureza + ", " +
      to_string(this->tamanho)+ "]";
  }
};

class lapiseira {
  grafite* graf;
  public:
  float calibre;
  bool grafOn = false;
  map<string, int> degrade {
    {"HB", 1},
    {"2B", 2},
    {"4B", 4},
    {"6B", 6}
  };
  lapiseira() { }
  lapiseira(float calibre) : calibre(calibre) { }
  
  bool insertGraffiti(grafite& graf) {
    if(this->grafOn) {
      cout<<"warning: grafite já inserido\n";
      return false;
    }
    if(graf.calibre != this->calibre) {
      cout<<"warning: grafite incompatível\n";
      return false;
    }
    delete this->graf;
    this->graf = &graf;
  
    this->grafOn = true;
    return true;
  }
  grafite* remove() {
    if(!grafOn) {
      cout << "warning: sem grafite";
      return nullptr;
    }
    grafOn = false; 
    return std::exchange(this->graf, nullptr);
  }
  void write(int sheets) {
    if(!this->grafOn) {
      cout << "warning: sem grafite\n";
      return;
    }
    int completed = sheets;
    while(sheets>0 && this->graf->tamanho>0) {
      sheets--;
      this->graf->tamanho -= 
        degrade[this->graf->dureza];
    }
    completed -= sheets;
    if(this->graf->tamanho == 0) {
      cout << "warning: o grafite acabou\n";
    }
    if(sheets > 0) {
      cout << "fail: folhas restantes "
      << sheets <<"\n";
    }
  }
  void toString(){
    cout << "calibre: " <<
    this->calibre;
    
    if(!this->grafOn){
      cout << ", grafite: null\n";
      return;
    }
    
    cout << ", grafite: [" <<
    this->graf->calibre << ", " <<
    this->graf->dureza << ", " <<
    this->graf->tamanho << "]\n";
    return;
  }
};

bool terminal(lapiseira& l) {
  cout << "$";
  string cmd;
  cin >> cmd;
  if(cmd == "end") {
    return false;
  }
  if(cmd == "init") {
    float c;
    cin >> c;
    l = lapiseira(c);
  }
  if(cmd == "write") {
    int sheets;
    cin >> sheets;
    l.write(sheets);
  }
  if(cmd == "insert") {
    float c;
    int t;
    string d;
    cin >> c >> d >> t;
    grafite g(c, d, t);
    
    l.insertGraffiti(g);
  }
  if(cmd == "remove") {
    cout << "removed " << 
    l.remove()->toString() << "\n";
  }
  if(cmd == "show") {
    l.toString();
  }
  
  return true;
}

int main() {
  lapiseira l;
  while(terminal(l));
}





