#include <iostream>
#include <list>
#include <sstream>
#include "kid.h"
#include "pula.h"

int main(){
    Trampoline t;
    Kid k("fagner", 18), k1("augusto", 18), k2("elza", 18);
    t.print();
    t.arrive(k);
    t.arrive(k1);
    t.arrive(k2);
    t.remove("augusto");
    t.print();
    t.in();
    t.in();
    t.in();
    t.print();
}


// #include <iostream>
// #include <sstream>
// #include <vector>
// #include <list>


// class Kid{
//     int idade;
//     std::string nome;
// public:
//     Kid(std::string nome, int idade) : nome(nome), idade(idade){
//     }

//     std::string get_name(){
//         return nome;
//     }

//     int  get_idade(){
//         return idade;
//     }

//     int set_idade(){
//         this->idade=idade;
//     } 

//     bool operator==(const Kid& kid){
//         return kid.nome==this->nome;
//     }
//     bool operator!=(const Kid& kid){
//         return kid.nome!=this->nome;
//     }



// };



// class Trampolim{
//     std::list<Kid> pulando;
//     std::list<Kid> esperando;
// public:
//     void entrar(){
//         pulando.push_back(esperando.front());
//         esperando.pop_front();
//     }

//     void sair(){
//        esperando.push_back(pulando.front());
//        pulando.pop_front();
//     }

//     void chegar(Kid crianca){
//         esperando.push_back(crianca);
//     }

//     ///remove de onde ela estiver
//     void remover(std::string nome){
//         Kid kid_vazia=Kid("nome", 0);
//         for(auto x: esperando ){
//             if(x.get_name() == nome){
//                 kid_vazia = x;
//             }
//         }
//         esperando.remove(kid_vazia);

//         for(auto x: pulando ){
//             if(x.get_name() == nome){
//                 kid_vazia = x;
//             }
//         }
//         pulando.remove(kid_vazia);
//     }

//     void printar(){
//         for(auto x: pulando ){
//             std::cout << "pulando: " << x.get_name() << "\n";
//         }
//         for(auto x: esperando ){
//             std::cout << "esperando: " << x.get_name() << "\n";
//         }
//     }

// };


// int main(){
//     Trampolim t;
//     Kid k("fagner", 18), k1("augusto", 18), k2("elza", 18);
//     t.printar();
//     t.chegar(k);
//     t.chegar(k1);
//     t.chegar(k2);
//     t.remover("augusto");
//     t.printar();
//     t.entrar();
//     t.entrar();
//     t.entrar();
//     t.printar();
// }