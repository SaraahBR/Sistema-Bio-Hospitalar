#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

struct Doenca
{
    string nome;
    vector<string> sintomas;
    vector<string> medicacoes;
};

struct Paciente
{
    string nome;
    int idade;
    string endereco;
    string convenio;
    string rg;
    string cpf;
    string diagnostico;
};

class Diagnostico
{
private:
    vector<Doenca> doencas;
    vector<Paciente> pacientes;

    string normalizarString(const string &entrada)
    {
        string resultado;
        for (char c : entrada)
        {
            if (isalnum(c) || isspace(c))
            {
                resultado += tolower(c);
            }
        }
        return resultado;
    }

    bool sintomaSimilar(const string &sintoma, const vector<string> &sintomas)
    {
        string sintomaNormalizado = normalizarString(sintoma);
        for (const auto &s : sintomas)
        {
            if (normalizarString(s) == sintomaNormalizado)
            {
                return true;
            }
        }
        return false;
    }

public:
    Diagnostico()
    {
        inicializarDoencas();
    }

    void inicializarDoencas()
    {
        doencas.push_back({"Gripe", {"febre", "tosse", "dor de garganta", "coriza", "fadiga", "calafrios"}, {"Paracetamol", "Vitamina C", "Antigripal", "Cha quente"}});
        doencas.push_back({"Covid-19", {"febre", "tosse", "falta de ar", "cansaco", "perda de olfato", "dor no peito"}, {"Ibuprofeno", "Dexametasona", "Hidroxicloroquina", "Ivermectina", "Nitazoxanida", "Remdesivir", "Azitromicina", "Oxigenoterapia"}});
        doencas.push_back({"Dengue", {"febre", "dor no corpo", "dor de cabeca", "manchas vermelhas", "dor atras dos olhos"}, {"Dipirona", "Hidratacao", "Paracetamol", "Soro intravenoso"}});
        doencas.push_back({"Amigdalite", {"dor de garganta", "febre", "dificuldade para engolir", "halitose"}, {"Antibiotico", "Ibuprofeno", "Paracetamol", "Spray anestesico"}});
        doencas.push_back({"Sinusite", {"dor facial", "congestao nasal", "secrecao amarelada", "dor de cabeca", "fadiga"}, {"Amoxicilina", "Analgesico", "Descongestionante", "Lavagem nasal"}});
        doencas.push_back({"Bronquite", {"tosse persistente", "falta de ar", "cansaco", "dor no peito", "chiado"}, {"Broncodilatador", "Corticosteroide", "Xarope", "Nebulizacao"}});
        doencas.push_back({"Asma", {"falta de ar", "tosse", "chiado", "cansaco", "opressao toracica"}, {"Inalador", "Broncodilatador", "Corticosteroide", "Teofilina"}});
        doencas.push_back({"Tuberculose", {"tosse com sangue", "febre", "suor noturno", "perda de peso", "fadiga"}, {"Rifampicina", "Isoniazida", "Pirazinamida", "Etambutol"}});
        doencas.push_back({"Otite", {"dor no ouvido", "febre", "secrecao", "perda auditiva", "inchaco"}, {"Antibiotico", "Analgesico", "Anti-inflamatorio", "Compressa morna"}});
        doencas.push_back({"Rinite", {"espirros", "coriza", "coceira nasal", "congestao nasal", "lacrimejamento"}, {"Antialergico", "Spray nasal", "Descongestionante", "Corticoide nasal"}});
        doencas.push_back({"Varicela", {"febre", "coceira", "manchas vermelhas", "bolhas no corpo"}, {"Antihistaminico", "Locao calmante", "Paracetamol"}});
        doencas.push_back({"Sarampo", {"febre alta", "tosse", "manchas vermelhas", "conjuntivite", "coriza"}, {"Vitamina A", "Hidratacao", "Analgesicos"}});
        doencas.push_back({"Hepatite A", {"ictericia", "fadiga", "dor abdominal", "urina escura"}, {"Reposicao de liquidos", "Hepatoprotetor"}});
        doencas.push_back({"Rubeola", {"febre baixa", "manchas vermelhas", "dor nas articulacoes"}, {"Analgesico", "Repouso", "Hidratacao"}});
        doencas.push_back({"Caxumba", {"dor na mandibula", "inchaco na regiao do rosto", "febre"}, {"Compressa morna", "Analgesicos", "Hidratacao"}});
        doencas.push_back({"Zika", {"febre", "manchas vermelhas", "dor nas articulacoes", "coceira"}, {"Paracetamol", "Hidratacao"}});
        doencas.push_back({"Ebola", {"febre", "hemorragia", "fadiga", "vomitos"}, {"Reposicao de liquidos", "Oxigenoterapia"}});
        doencas.push_back({"Raiva", {"febre", "hidrofobia", "salivacao excessiva", "paralisia"}, {"Vacina antirrabica", "Soro antirrabico"}});
        doencas.push_back({"Chikungunya", {"febre", "dor intensa nas articulacoes", "manchas vermelhas", "fadiga"}, {"Analgesico", "Hidratacao"}});
        doencas.push_back({"HPV", {"verrugas genitais", "coceira"}, {"Acido tricloroacetico", "Crioterapia"}});
        doencas.push_back({"Malaria", {"febre", "calafrios", "suor excessivo", "dor de cabeca"}, {"Cloroquina", "Artemisinina"}});
        doencas.push_back({"Toxoplasmose", {"fadiga", "febre", "dor muscular", "inchaco dos linfonodos"}, {"Pirimetamina", "Sulfadiazina"}});
        doencas.push_back({"Amebiase", {"dor abdominal", "diarreia com sangue", "febre"}, {"Metronidazol", "Diloxanida"}});
        doencas.push_back({"Giardiase", {"diarreia", "dor abdominal", "gases", "nausea"}, {"Metronidazol", "Tinidazol"}});
        doencas.push_back({"Doenca de Chagas", {"febre", "inchaco", "fadiga", "palpitacoes"}, {"Benzonidazol", "Nifurtimox"}});
        doencas.push_back({"Leishmaniose", {"feridas na pele", "febre", "perda de peso"}, {"Anfotericina B", "Miltefosina"}});
        doencas.push_back({"Esquistossomose", {"sangue nas fezes", "dor abdominal", "diarreia"}, {"Praziquantel"}});
        doencas.push_back({"Filariose", {"inchaco", "febre", "dor nos membros"}, {"Dietilcarbamazina", "Ivermectina"}});
        doencas.push_back({"Ascariose", {"dor abdominal", "diarreia", "tosse"}, {"Albendazol", "Mebendazol"}});
        doencas.push_back({"Teníase", {"dor abdominal", "perda de peso", "diarreia"}, {"Praziquantel"}});
        doencas.push_back({"Candidiase", {"coceira", "vermelhidao", "dor ao urinar", "corrimento branco"}, {"Fluconazol", "Clotrimazol"}});
        doencas.push_back({"Pe de atleta", {"coceira nos pes", "descamacao", "vermelhidao"}, {"Terbinafina", "Clotrimazol"}});
        doencas.push_back({"Histoplasmose", {"febre", "tosse", "fadiga", "dor no peito"}, {"Itraconazol", "Anfotericina B"}});
        doencas.push_back({"Esporotricose", {"feridas na pele", "vermelhidao", "inchaco"}, {"Itraconazol", "Terbinafina"}});
        doencas.push_back({"Onicomicose", {"unha amarelada", "espessamento da unha", "fragilidade"}, {"Terbinafina", "Amorolfina"}});
        doencas.push_back({"Pitiríase", {"manchas brancas", "descamacao"}, {"Cetoconazol", "Sulfeto de selenio"}});
        doencas.push_back({"Criptococose", {"febre", "dor de cabeca", "rigidez na nuca"}, {"Fluconazol", "Anfotericina B"}});
        doencas.push_back({"Paracoccidioidomicose", {"lesoes na pele", "febre", "tosse"}, {"Itraconazol", "Sulfametoxazol"}});
        doencas.push_back({"Coccidioidomicose", {"febre", "fadiga", "tosse"}, {"Fluconazol", "Itraconazol"}});
        doencas.push_back({"Blastomicose", {"lesoes cutaneas", "febre", "fadiga"}, {"Anfotericina B", "Itraconazol"}});
        doencas.push_back({"Anemia", {"fadiga", "palidez", "falta de ar", "tontura", "dor de cabeca", "maos e pes frios", "fraqueza", "palpitacoes"}, {"Sulfato ferroso", "Vitamina B12", "Acido folico", "Suplementos de ferro"}});
        doencas.push_back({"Infeccao urinaria", {"dor ao urinar", "urgencia urinaria", "urina turva", "odor forte", "febre baixa", "dor pelvica", "fadiga", "sangue na urina"}, {"Nitrofurantoina", "Fosfomicina", "Ciprofloxacino", "Amoxicilina"}});
        doencas.push_back({"Gastroenterite", {"nausea", "vomitos", "diarreia", "dor abdominal", "febre", "fadiga", "perda de apetite", "desidratacao"}, {"Soro oral", "Loperamida", "Paracetamol", "Hidratantes intravenosos"}});
        doencas.push_back({"Enfisema pulmonar", {"falta de ar", "tosse persistente", "fadiga", "dor toracica", "perda de peso", "fraqueza", "inchaco nas pernas", "coloracao azulada nos labios"}, {"Broncodilatadores", "Corticosteroides", "Oxigenoterapia", "Reabilitacao pulmonar"}});
        doencas.push_back({"Hipotireoidismo", {"fadiga", "aumento de peso", "pele seca", "queda de cabelo", "sensacao de frio", "constipacao", "depressao", "rouquidao"}, {"Levotiroxina", "Suplementacao de iodo", "Multivitaminicos", "Dieta equilibrada"}});
        doencas.push_back({"Hipoglicemia", {"tontura", "confusao mental", "suor frio", "palpitacoes", "fome excessiva", "tremores", "fraqueza", "visao turva"}, {"Glicose oral", "Dextrose intravenosa", "Suco de frutas", "Alimentos ricos em carboidratos"}});
        doencas.push_back({"Herpes labial", {"formigamento", "coceira", "vermelhidao", "bolhas dolorosas", "febre baixa", "dor muscular", "fadiga", "ganglios inchados"}, {"Aciclovir", "Valaciclovir", "Pomadas antivirais", "Compressas frias"}});
        doencas.push_back({"Bronquiolite", {"tosse", "falta de ar", "chiado", "febre baixa", "fadiga", "respiracao rapida", "narinas dilatadas", "tosse com secrecao"}, {"Nebulizacao", "Oxigenoterapia", "Broncodilatadores", "Hidratacao"}});
        doencas.push_back({"Antraz", {"feridas negras", "febre", "fadiga", "dor muscular", "tosse", "dor no peito", "falta de ar", "nausea"}, {"Ciprofloxacino", "Doxiciclina", "Rifampicina", "Vacinacao preventiva"}});
        doencas.push_back({"Febre tifoide", {"febre alta", "dor abdominal", "diarreia", "perda de apetite", "fraqueza", "dor de cabeca", "tosse seca", "confusao mental"}, {"Ciprofloxacino", "Azitromicina", "Ceftriaxona", "Reposicao de liquidos"}});
        doencas.push_back({"Sindrrome do intestino irritavel", {"dor abdominal", "inchaco", "gases", "diarreia", "constipacao", "fadiga", "nausea", "perda de apetite"}, {"Antiespasmodicos", "Laxantes", "Probioticos", "Dieta rica em fibras"}});
    }

    void registrarPaciente()
    {
        Paciente novoPaciente;
        cout << "Digite o nome do paciente: ";
        cin.ignore();
        getline(cin, novoPaciente.nome);

        cout << "Digite a idade do paciente: ";
        cin >> novoPaciente.idade;
        cin.ignore();

        cout << "Digite o endereco do paciente: ";
        getline(cin, novoPaciente.endereco);

        cout << "Digite o convenio medico do paciente: ";
        getline(cin, novoPaciente.convenio);

        cout << "Digite o RG do paciente: ";
        getline(cin, novoPaciente.rg);

        cout << "Digite o CPF do paciente: ";
        getline(cin, novoPaciente.cpf);

        diagnosticarPaciente(novoPaciente);
    }

    void diagnosticarPaciente(Paciente &paciente)
    {
        string sintoma;
        vector<string> sintomasPaciente;
        int contadorSintomas = 1;

        cout << "Digite os sintomas do paciente (digite 'fim' para terminar):" << endl;
        cin.ignore();
        while (true)
        {
            cout << contadorSintomas << " sintoma: ";
            getline(cin, sintoma);

            if (sintoma == "fim")
            {
                break;
            }

            sintomasPaciente.push_back(normalizarString(sintoma));
            contadorSintomas++;
        }

        map<string, int> correspondencias;
        for (const auto &doenca : doencas)
        {
            int count = 0;
            for (const auto &sintoma : sintomasPaciente)
            {
                if (sintomaSimilar(sintoma, doenca.sintomas))
                {
                    count++;
                }
            }
            correspondencias[doenca.nome] = count;
        }

        vector<pair<string, int>> ordenado(correspondencias.begin(), correspondencias.end());
        sort(ordenado.begin(), ordenado.end(), [](const pair<string, int> &a, const pair<string, int> &b)
             { return a.second > b.second; });

        cout << "\nDiagnosticos possiveis:" << endl;
        int totalSintomas = sintomasPaciente.size();
        int exibidos = 0;
        for (const auto &item : ordenado)
        {
            if (exibidos >= 3)
                break;

            double porcentagem = (static_cast<double>(item.second) / totalSintomas) * 100.0;
            cout << item.first << " (" << porcentagem << "%)";

            if (exibidos < 2 && item.second > 0)
                cout << ", ";

            exibidos++;
        }
        cout << ".\n";

        if (!ordenado.empty())
        {
            cout << "\nMedicacoes recomendadas:\n";
            for (int i = 0; i < min(3, (int)ordenado.size()); i++)
            {
                cout << ordenado[i].first << ": ";
                for (const auto &doenca : doencas)
                {
                    if (doenca.nome == ordenado[i].first)
                    {
                        for (const auto &medicacao : doenca.medicacoes)
                        {
                            cout << medicacao << " ";
                        }
                        break;
                    }
                }
                cout << endl;
            }
        }

        cout << "\nE necessario realizar exames de sangue e outros tipos para confirmar o Diagnostico Perfeito, verifique com o medico do/da paciente.\n";
        pacientes.push_back(paciente);
    }

    void listarPacientes()
    {
        if (pacientes.empty())
        {
            cout << "Nenhum paciente registrado." << endl;
            return;
        }

        cout << "\nLista de Pacientes e Diagnosticos:" << endl;
        for (const auto &paciente : pacientes)
        {
            cout << "Nome: " << paciente.nome
                 << ", Idade: " << paciente.idade
                 << ", Endereco: " << paciente.endereco
                 << ", Convenio: " << paciente.convenio
                 << ", RG: " << paciente.rg
                 << ", CPF: " << paciente.cpf
                 << ", Diagnostico: " << paciente.diagnostico << endl;
        }
    }

    void executarSistema()
    {
        int opcao;
        do
        {
            cout << "\n=== Sistema de Diagnostico ===" << endl;
            cout << "1. Registrar Paciente" << endl;
            cout << "2. Listar Pacientes" << endl;
            cout << "3. Sair" << endl;
            cout << "Escolha uma opcao: ";
            cin >> opcao;

            switch (opcao)
            {
            case 1:
                registrarPaciente();
                break;
            case 2:
                listarPacientes();
                break;
            case 3:
                cout << "Encerrando o sistema." << endl;
                break;
            default:
                cout << "Opcao invalida. Tente novamente." << endl;
            }
        } while (opcao != 3);
    }
};

int main()
{
    Diagnostico diagnostico;
    diagnostico.executarSistema();
    return 0;
}