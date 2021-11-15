#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

class child {
  public:
  int age;
  std::string name;
  child(std::string name, int age) : name(name), 
  age(age) {
    
  }
};

class motorcycle {
  public:
  std::vector<child> chlds;
  int power;
  int rideTime = 0;
  motorcycle() {}
  motorcycle(int power) : power(power) {}
  
  void goIn(child chld) {
    if(this->chlds.size() > 3) {
      std::cout << "moto cheia\n";
      return;
    }
    this->chlds.push_back(chld);
  }
  
  std::vector<child> goOut() {
    if(this->chlds.size() == 0) {
      std::cout << "moto vazia";
      return std::vector<child>();
    }
    return std::exchange(this->chlds, {});
  }
  
  void buy(int rideTime) {
    this->rideTime += rideTime;
  }
  
  void drive(int rideTime) {
    if(this->rideTime - rideTime < 0) {
      std::cout<<"tempo acabou\n";
      std::cout<<"tempo passado: " 
      << rideTime - (rideTime - this->rideTime)
      << "\n";
      this->rideTime = 0;
      return;
    }
    this->rideTime -= rideTime;
  }
  
  void honk() {
    if(chlds.size() == 0) {
     std::cout << "moto vazia\n";
     return;
    }
    std::string a(this->power, 'e');
    std::cout<<'P' << a << "m\n";
  }
  
  std::string toString() {
    std::string out = "potencia: " + 
      std::to_string(this->power) +
      ", minutos: " + 
      std::to_string(this->rideTime) +
      ", pessoas: [";
    for (auto& x : this->chlds) {
      out += x.name;
    }
    out += "]\n";
    return out;
  }
  
};

std::ostream &operator<<(std::ostream& os, const std::vector<child>& o) {
  for(auto& x : o) {
    os << x.name;
  }
  return os;
}

bool terminal(motorcycle& l) {
  std::cout << "$";
  std::string cmd;
  std::cin >> cmd;
  if(cmd == "end") {
    return false;
  }
  if(cmd == "init") {
    int c;
    std::cin >> c;
    l = motorcycle(c);
  }
  if(cmd == "drive") {
    int sheets;
    std::cin >> sheets;
    l.drive(sheets);
  }
  if(cmd == "buy") {
    int rideTime;
    std::cin >> rideTime;
    l.buy(rideTime);
  }
  if(cmd == "honk") {
    l.honk();
  }
  if(cmd == "insert") {
    int c;
    std::string d;
    std::cin >> d >> c;
    child g(d, c);
    
    l.goIn(g);
  }
  
  if(cmd == "remove") {
    std::cout << "removed " << l.goOut() << "\n";
  }
  
  if(cmd == "show") {
    std::cout << l.toString();
  }
  
  return true;
}

int main() {
  motorcycle motor;
  while(terminal(motor));
}
