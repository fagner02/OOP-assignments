#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

std::ostream& operator<<(std::ostream& os,
 const std::vector<int> v) {
   if(v.size()<1){
     os << "[]";
     return os;
   }
   os << "[" << v[0];
   for (int i = 1; i<(int)v.size();i++) {
     os << ", " << v[i];
   }
   os << "]";
   return os;
}

int indexOf(std::vector<int> line, int x) {
  
  int index = 
    static_cast<int>(std::find(line.begin(),
    line.end(), x) - line.begin());
 
  return (index >= static_cast<int>(line.size()))?
  -1 : index;
}

template <typename T, typename Pred>
T filter(T a, Pred b) {
  T c;
  for (auto& x : a) {
    if (b(x)) {
      c.push_back(x);
    }
  }
  
  return c;
}

std::vector<int> clone
(const std::vector<int>& v) {
  std::vector<int> copy = v;
  return copy;
}

std::vector<int> pegar_homens
(const std::vector<int>& v) {
  return filter(v, [](auto& elem){
    return (elem > 0);
  });
}

std::vector<int> pegar_calmos
(const std::vector<int>& v) {
  return filter(v, [](auto& elem){
    return (abs(elem) < 10);
  });
}

std::vector<int> pegar_mulheres_calmas
(const std::vector<int>& v) {
  return filter(v, [](auto& elem){
    return (elem < 0 && abs(elem) < 10);
  });
}

std::vector<int> inverter_com_copia
(const std::vector<int>& v) {
  std::vector<int> copy = v;
  std::reverse(copy.begin(), copy.end());
  return copy;
}

void reverter_inplace
(std::vector<int>& v) {
  std::reverse(v.begin(), v.end());
}

int sortear(const std::vector<int>& v) {
  int index = rand() % v.size();
  return v[index];
}

void embaralhar(std::vector<int>& v) {
  int index {};
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    index = rand() % v.size();
    std::swap(v[i], v[index]);
  }
}

void ordenar(std::vector<int>& v) {
  std::sort(v.begin(), v.end());
}

std::vector<int> exclusivos(const std::vector<int>& v) {
  std::vector<int> exclusive {};
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (std::find(exclusive.begin(), 
    exclusive.end(), v[i]) == exclusive.end()) {
      exclusive.push_back(v[i]);
    }
  }
  return exclusive;
}

std::vector<int> diferentes
(const std::vector<int>& v) {
  std::vector<int> levelSet {};
  for (auto& x : v) {
    if (std::find(levelSet.begin(), 
    levelSet.end(), abs(x)) == levelSet.end()) {
      levelSet.push_back(abs(x));
    }
  }
  return levelSet;
}

std::vector<int> abandonados
(const std::vector<int>& v) {
  std::vector<int> copy = v;
  for (auto& x : exclusivos(v)) {
    auto it = std::find(copy.begin(),
    copy.end(), x);
    if (it != copy.end()) {
      copy.erase(it);
    }
  }
  return copy;
}

int main() {
  srand(time(NULL));
  std::vector<int> v
  {-3, 56, 56, -6, 56, -6, 7,
  -67, -6, 60, 60, 7, -98};
  
  std::cout << pegar_homens(v) << "\n";
  std::cout << pegar_calmos(v) << "\n";
  std::cout << inverter_com_copia(v) << "\n";
  std::cout << pegar_mulheres_calmas(v) << "\n";
  std::cout << v << "\n";
  reverter_inplace(v);
  std::cout << v << "\n";
  std::cout << sortear(v) << "\n";
  embaralhar(v);
  std::cout << v << "\n";
  ordenar(v);
  std::cout << v << "\n";
  std::cout << exclusivos(v) << "\n";
  std::cout << diferentes(v) << "\n";
  std::cout << abandonados(v) << "\n";
}

