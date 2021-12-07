#include <bits/stdc++.h>

std::string search(std::vector<int> line, int x) {
  return (std::find(line.begin(), line.end(), x) 
    != line.end())? "true" :
  "false";
}

int count(std::vector<int> line, int x) {
  return std::count(line.begin(), line.end(), x);
}

int indexOf(std::vector<int> line, int x) {
  
  int index = 
    static_cast<int>(std::find(line.begin(),
    line.end(), x) - line.begin());
 
  return (index >= static_cast<int>(line.size()))?
  -1 : index;
}

int indexFrom(std::vector<int> line, 
int pos, int x) {
  int index = 
    static_cast<int>(std::find(line.begin() + pos,
    line.end(), x) - line.begin());
 
  return (index >= static_cast<int>(line.size()))?
  -1 : index;
}

int min(std::vector<int> line) {
  return *std::min_element(line.begin(),
  line.end());
}

int max(std::vector<int> line) {
  return *std::max_element(line.begin(),
  line.end());
}

int minPos(std::vector<int> line) {
  int index =
  static_cast<int>(std::min_element(line.begin(),
  line.end()) - line.begin());
  
  return index;
}

int minPosFrom(std::vector<int> line, int pos) {
  int index =
  static_cast<int>(
  std::min_element(line.begin() + pos,
  line.end()) - line.begin());
  
  return (index >= static_cast<int>(line.size()))?
  -1 : index;
}

int minPositivePos(std::vector<int> line) {
  std::vector<int> temp;
  for (auto x : line) {
    if(x > 0) {
      temp.push_back(x);
    }
  }
  int minValue = 
    *std::min_element(temp.begin(), temp.end());
  return 
   static_cast<int>
   (std::find(line.begin(), line.end(), minValue)
   - line.begin());
}

int absAccumulate(int sum, int value) {
  return sum += abs(value);
}
float average(std::vector<int> line) {
  return 
  std::abs(1.0 * std::accumulate(line.begin(),
  line.end(), 0, absAccumulate) / (1.0 * line.size()));
}

std::string mode(std::vector<int> line) {
  int h = 0, m = 0;
  for (auto x : line) {
    if(x < 0) {
      m++;
    } else {
      h++;
    }
  }
  if(h == m) {return "Igual";}
  return (h < m)? "Mulheres" : "Homens";
}

std::string modeMax(std::vector<int> line) {
  int h = 0, m = 0;
  for (auto x : line) {
    if(x < 0) {
      m += std::abs(x);
    } else {
      h += x;
    }
  }
  if(h == m) {return "Igual";}
  return (h < m)? "Mulheres" : "Homens";
}

std::string modeAverage(std::vector<int> line) {
  int h = 0, hs = 0;
  int m = 0, ms = 0;
  for (auto x : line) {
    if(x < 0) {
      m += std::abs(x);
      ms++;
    } else {
      h += x;
      hs++;
    }
  }
  h /= hs;
  m /= ms;
  return (h > m)? "Sim" : "Não";
}

int main() {
    std::vector<int> line;
    int size {};
    
    std::cout << 
    "insira o tamanho da fila:\n";
    std::cin >> size;
    
    std::cout << 
    "insira os números da fila\n\ 
separados por espaço:\n";
    for (int i = 0; i < size; i++) {
      int temp {};
      
      std::cin >> temp;
      
      line.insert(line.end(), temp);
    }
    
    int x {};
    int pos {};
    
    std::cout << 
    "insira um número para a busca:\n"; 
    std::cin >> x;
    std::cout << "Existe: " 
    << search(line, x) << "\n\n";
    
    std::cout << 
    "insira um número para a contagem:\n"; 
    std::cin >> x;
    std::cout << "Contagem: "
    << count(line, x) << "\n\n";
    
    std::cout << 
    "insira um número para a busca da posição:\n"; 
    std::cin >> x;
    std::cout << "Posição: " 
    << indexOf(line, x) << "\n\n";
    
    std::cout << 
    "insira um número de onde começar a busca:\n"; 
    std::cin >> pos;
    std::cout << 
    "insira um número para a busca da posição:\n"; 
    std::cin >> x;
    std::cout << "Posição: "
    << indexFrom(line, pos, x) << "\n\n";
    
    std::cout << "Menor valor:\n"; 
    std::cout << min(line) << "\n\n";
    
    std::cout << "Maior valor:\n"; 
    std::cout << max(line) << "\n\n";
    
    std::cout << "Posição do menor valor:\n"; 
    std::cout << minPos(line) << "\n\n";
    
    std::cout << 
    "insira um número de onde começar a busca:\n"; 
    std::cin >> pos;
    std::cout << "Posição do menor valor a\
partir da posição " << pos << ":\n"; 
    std::cout << minPosFrom(line, pos) << "\n\n";
    
    std::cout << "Posição do homem mais calmo:\n"; 
    std::cout << minPositivePos(line) << "\n\n";
    
    std::cout << "Média:\n";
    std::cout << average(line) << "\n\n";
    
    std::cout << "Mais homens ou mulheres: ";
    std::cout << mode(line) << "\n\n";
    
    std::cout << "Quem é mais estressado: ";
    std::cout << modeMax(line) << "\n\n";
    
    std::cout << "Homens são mais estressados:\n";
    std::cout << modeAverage(line) << "\n\n";
}
