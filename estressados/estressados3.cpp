#include <iostream>

#include <vector>

#include <algorithm>

#include <ctime>

#include <map>

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

std::ostream& operator<<(std::ostream& os,

 const std::map<int, int> m) {

   if(m.size()<1){

     os << "[]";

     return os;

   }

   os << "[" << m.begin()->first;

   for (auto& [key, value] : m) {

     os << key << ": " << value << ", ";

   }

   os << "]";

   return os;

}

std::vector<int> sozinhos(const std::vector<int>& v) {

  std::vector<int> loners;

  for(auto& x : v) {

    if(std::count_if(v.begin(), v.end(), 

    [&](auto& n){

      return abs(n) == abs(x);

    }) < 2) {

      loners.push_back(abs(x));

    }

  }

  return loners;

}

int mais_ocorrencias(std::vector<int>& v) {

  std::map<int, int> occurs;

  for (auto& x : v) {

    occurs[abs(x)] += 1;

  }

  

  return max_element(occurs.begin(), 

  occurs.end(), [](auto& p1, auto& p2){

    return p1.second < p2.second;

  })->second;

}

std::vector<int> mais_recorrentes(std::vector<int>& v) {

  std::vector<int> reccurs;

  int maxOccur = mais_ocorrencias(v);

  for (auto& x : v) {

    if (std::count_if(v.begin(), v.end(), 

    [&](auto& n){

      return abs(n) == abs(x);

    }) == maxOccur 

    && std::find(reccurs.begin(), 

    reccurs.end(), abs(x)) == reccurs.end()) {

      reccurs.push_back(abs(x));

    }

  }

  return reccurs;

}

 

int briga(std::vector<int>& v) {

  int out{};

  for (int i = 0; i < static_cast<int>(v.size()); i++) {

    if( i == 0 || i == -1 + v.size()) {

      continue;

    }

    if(abs(v[i]) > 50 && abs(v[i - 1]) > 30 && 

    abs(v[i + 1]) > 30) {

      out++;

    }

  }

  return out;

}

std::vector<int> apaziguado(std::vector<int>& v) {

  std::vector<int> out;

  for (int i = 0; i < static_cast<int>(v.size()); i++) {

    if(abs(v[i]) > 80 &&

     ((i > 0 && abs(v[i - 1]) < 10) || 

     (i < -1 + v.size() && abs(v[i + 1]) < 10)))

    {

      out.push_back(i);

    }

  }

  return out;

}

int quantos_times(std::vector<int>& v) {

  int out {};

  int last {};

  bool added = false;

  for (auto& x : v) {

    if(x < 0) {

      if(last == -1) {

        if(!added){

          out++;

          added = true;

        }

      } else {

        added = false;

      }

      last = -1;

    }

    

    if(x > 0) {

      if(last == 1) {

        if(!added){

          out++;

          added = true;

        }

      } else {

        added = false;

      }

      last = 1;

    }

  }

  return out;

}

int maior_time(std::vector<int>& v) {

  int neg {};

  int pos {};

  int temp {1};

  int last {};

  bool added = false;

  for (auto& x : v) {

    if(x < 0) {

      if(last == -1) {

        temp++;

      } else {

        if(temp > neg && temp > 1) {

          neg = temp;

        }

        temp = 1;

      }

      last = -1;

    }

    

    if(x > 0) {

      if(last == 1) {

        temp++;

      } else {

        if(temp > pos && temp > 1) {

          pos = temp;

        }

        temp = 1;

      }

      last = 1;

    }

  }

  return (pos > neg)? pos : neg;

}

std::vector<int> sozinhos2(const std::vector<int>& v) {

  std::vector<int> loners;

  for(int i = 0; i < static_cast<int>(v.size()); i++) {

    if(v[i] < 0 && 

      (((i > 0 && v[i - 1] > 0) || i == 0) &&

      ((i < (int) v.size() - 1 && v[i + 1] > 0) ||

      i == (int) v.size() -1))

    ) {

      loners.push_back(v[i]);

    }

    if(v[i] > 0 && 

      (((i > 0 && v[i - 1] < 0) || i == 0) &&

      ((i < (int) v.size() - 1 && v[i + 1] < 0) ||

      i == (int) v.size() -1))

    ) {

      loners.push_back(v[i]);

    }

  }

  

  return loners;

}

int duplas(std::vector<int>& v) {

  int out{};

  std::map<int, int> matches;

  for (int i = 0; i < static_cast<int>(v.size()); i++) {

    if(matches.find(abs(v[i])) != matches.end()){

      continue;

    }

    

    int neg = std::count(v.begin(), 

    v.end(), v[i] * -1);

    int pos = std::count(v.begin(), 

    v.end(), v[i]);

    matches[abs(v[i])] = (neg < pos)? neg : pos;

  }

  

  for (auto& [key, value] : matches) {

    out += value;

  }

  return out;

}

int trios(std::vector<int>& v) {

  int out {};

  std::map<int, int> matches;

  for (auto& x : v) {

    

    matches[abs(x)] = [] (std::vector<int>& v, int x)

    -> int {

      int out {};

      for (auto& y : v) {

        if(abs(y) == abs(x)) {

          out++;

        }

      }

      return out;

    }(v, x);

  }

  for (auto& [key, value] : matches) {

    out += value / 3;

  }

  return out;

}

void remove(std::vector<int>& v, int x) {

  v.erase(std::find(v.begin(), v.end(), x));

}

void insert(std::vector<int>& v, int x, int pos) {

  v.insert(v.begin()+pos, x);

}

void dance(std::vector<int>& v) {

  for(int i =0; i < (int)v.size(); i++) {

    if(i < (int)v.size() - 1 && 

    abs(v[i]) == abs(v[i + 1])) {

      v.erase(v.begin()+i);

      v.erase(v.begin()+i);

      i -= 2;

      i = (i < 0)? -1 : i;

    }

  }

}

int main() {  

  std::vector<int> v

  {-3, 56, 56, -6, -6, 56, 7,

  -67, -6, 60, 60, 70, 6, -98, 10};

  

  std::cout << sozinhos(v) << "\n";

  std::cout << mais_ocorrencias(v) << "\n";

  std::cout << mais_recorrentes(v) << "\n";

  std::cout << briga(v) << "\n";

  std::cout << apaziguado(v) << "\n";

  std::cout << quantos_times(v) << "\n";

  std::cout << maior_time(v) << "\n";

  std::cout << sozinhos2(v) << "\n";

  std::cout << duplas(v) << "\n";

  std::cout << trios(v) << "\n";

  remove(v, 56);

  std::cout << v << "\n";

  insert(v, 70, 11);

  std::cout << v << "\n";

  dance(v);

  std::cout << v << "\n";

}

