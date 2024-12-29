#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>

using namespace std;

//Funcao Selection Sort
void selectionSort(vector<int>& numbers) {
    for (int i = 0; i < numbers.size(); i++) {
        int min = i;
        for (int j = i + 1; j < numbers.size(); j++) {
            if (numbers[j] < numbers[min]) {
                min = j;
            }
        }
        if (min != i) {
            swap(numbers[i], numbers[min]);
        }
    }

    for (int i = 0; i < numbers.size(); i++) {
        cout << numbers[i] << endl;
    }
}

//Funcao Insertion Sort
void insertionSort(vector<int>& numbers) {
    for(int i = 0; i < numbers.size(); i++) {
        int j = i;
        while(j > 0 && numbers[j] < numbers[j - 1]) {
            swap(numbers[j], numbers[j - 1]);
            j--;
        }
    }
    for (int i = 0; i < numbers.size(); i++) {
        cout << numbers[i] << endl;
    }
}


int main() {

    //Variavel para medir o tempo de execucao
    auto start = chrono::high_resolution_clock::now();

    //Abre o arquivo para leitura, isso vai depender de onde esta no computador, este é meu diretorio, por isso esses nomes
    ifstream file("C:\\Users\\Casa\\Documents\\Faculdade\\P4\\Estrutura de Dados\\instancias-num\\num.100000.1.in");

    //Verificacao de erro ao abrir o arquivo
    if (!file.is_open()) {
        cout << "Erro ao abrir arquivo" << endl;
        return 1;
    }
    
    //Cria um vetor de inteiros para armazenar os numeros do arquivo
    vector<int> numbers;
    string line;
    while (getline(file, line)) {
        numbers.push_back(stoi(line));
    }

    cout << "Algoritmo de ordenacao" <<endl;
    cout << "1 - Selection Sort" << endl;
    cout << "2 - Insertion Sort" << endl;
    cout << "Digite o numero do algoritmo de ordenacao: ";
    int opcao;
    cin >> opcao;

    if(opcao == 1) {
        selectionSort(numbers);
    } else if(opcao == 2) {
        insertionSort(numbers);
    } else {
        cout << "Opcao invalida" << endl;
        return 1;
    }

    //Fecha o arquivo
    file.close();

    //Variavel para medir o tempo de execucao
    auto fim = chrono::high_resolution_clock::now();

    //Calcula o tempo de execucao
    chrono::duration<double> tempo = chrono::duration_cast<chrono::duration<double>>(fim - start);
    cout << "Tempo de execucao: " << tempo.count() << " segundos" << endl;

    
    return 0;
}