#include <iostream>
using namespace std;

int main(){
  int a, b, size, turns;
  string input ("");
  string out("b wins\n");
  while (input!="q"){
    cout<<"Digite o número de itens\n";
    cin>>input;    
    if(input =="q") break;
    try{
      size = stoi(input);
    }catch(invalid_argument){
      cout<<"invalid input\n";
      continue;
    }
    out = "b wins\n";
    while((size%2==0 || size < 3)){
      cout<<"Digite um número ímpar maior \n"
      <<"que ou igual a 3\n";
      cin>>size;
    }
    cout<<"Digite os itens dos dois jogadores\n";
    cin>>a>>b;
  
    turns = (((size-1)/2));
    int lim = a+turns;
    if((b > a && b <= lim) ||
    ((b > a || b <= lim) && lim < a+1)){
        out = "a wins\n";
    }
    if(a == b){
        out = "draw\n";
    }
    cout << out;
  }
}
