#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Paciente {
    int id;
    string nome;
    int idade;
    string dnaSequence;
    string tipoSanguineo;
    string doencas;
    string endereco;
};

class Sistema_Hospitalar_DNA {
private:
    vector<Paciente> pacientes;
    int proximoId;

    bool analisarDNA(const string& dna) {
        string mutacao = "ATCGG";
        return dna.find(mutacao) != string::npos;
    }

public:
    Sistema_Hospitalar_DNA() : proximoId(1) {}

    void registrarPaciente() {
        Paciente novoPaciente;
        novoPaciente.id = proximoId++;

        cout << "Digite o nome do paciente: ";
        cin.ignore();
        getline(cin, novoPaciente.nome);

        cout << "Digite a idade do paciente: ";
        cin >> novoPaciente.idade;

        cout << "Digite a sequencia de DNA do paciente: ";
        cin >> novoPaciente.dnaSequence;

        cin.ignore();
        cout << "Digite o tipo sanguineo do paciente (ex: O+, A-, etc.): ";
        getline(cin, novoPaciente.tipoSanguineo);

        cout << "O paciente possui alguma doenca? (Descreva ou digite 'Nenhuma'): ";
        getline(cin, novoPaciente.doencas);

        cout << "Digite o endereco do paciente: ";
        getline(cin, novoPaciente.endereco);

        pacientes.push_back(novoPaciente);
        cout << "Paciente registrado com sucesso! ID: " << novoPaciente.id << endl;
    }

    void exibirPacientes() {
        if (pacientes.empty()) {
            cout << "Nenhum paciente registrado ainda." << endl;
            return;
        }

        cout << "\nLista de Pacientes:" << endl;
        for (const auto& paciente : pacientes) {
            cout << "ID: " << paciente.id
                 << ", Nome: " << paciente.nome
                 << ", Idade: " << paciente.idade
                 << ", DNA: " << paciente.dnaSequence
                 << ", Tipo Sanguineo: " << paciente.tipoSanguineo
                 << ", Doencas: " << paciente.doencas
                 << ", Endereco: " << paciente.endereco << endl;
        }
    }

    void realizarAnaliseDNA() {
        if (pacientes.empty()) {
            cout << "Nenhum paciente registrado para analise." << endl;
            return;
        }

        cout << "\nResultados da Analise de DNA:" << endl;
        for (const auto& paciente : pacientes) {
            cout << "Paciente: " << paciente.nome << " (ID: " << paciente.id << ") - ";
            if (analisarDNA(paciente.dnaSequence)) {
                cout << "Mutacao encontrada!" << endl;
            } else {
                cout << "Nenhuma mutacao detectada." << endl;
            }
        }
    }
};

int main() {
    Sistema_Hospitalar_DNA sistema;
    int opcao;

    do {
        cout << "\n=== Sistema Bioinformatica Hospitalar ===" << endl;
        cout << "1. Registrar Paciente" << endl;
        cout << "2. Exibir Pacientes" << endl;
        cout << "3. Realizar Analise de DNA" << endl;
        cout << "4. Sair" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                sistema.registrarPaciente();
                break;
            case 2:
                sistema.exibirPacientes();
                break;
            case 3:
                sistema.realizarAnaliseDNA();
                break;
            case 4:
                cout << "Encerrando o sistema. Ate mais!" << endl;
                break;
            default:
                cout << "Opcao invalida. Tente novamente." << endl;
        }
    } while (opcao != 4);

    return 0;
}
