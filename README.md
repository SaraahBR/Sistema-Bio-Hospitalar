# 🏥 Sistema Bio Hospitalar

O **Sistema Bio Hospitalar** é um sistema simples de diagnóstico médico desenvolvido em C++, que auxilia no reconhecimento de possíveis doenças com base nos sintomas informados pelo paciente. O sistema compara os sintomas inseridos com uma base interna de doenças e retorna as mais prováveis, junto com sugestões de medicações associadas.

<br>

## 📋 Funcionalidades

- Registro de pacientes com dados completos (nome, idade, endereço, convênio, RG e CPF)
- Entrada interativa dos sintomas apresentados
- Diagnóstico sugerido com base na similaridade dos sintomas
- Sugestão de medicações para as doenças mais prováveis
- Listagem dos pacientes registrados
- Normalização de strings para melhorar a precisão da comparação entre sintomas

<br>

## 🧠 Como funciona

O sistema utiliza uma base de dados interna contendo dezenas de doenças, cada uma com seus sintomas e medicações associadas. A cada entrada de sintomas de um paciente, o sistema:

1. Normaliza e armazena os sintomas informados.
2. Compara os sintomas com a lista de doenças cadastradas.
3. Calcula a quantidade de coincidências por doença.
4. Exibe até 3 diagnósticos possíveis, com porcentagem de similaridade.
5. Apresenta as medicações sugeridas para essas doenças.

<br>

## 🚀 Como executar

1. Compile o código com um compilador C++ (ex: `g++`):

```bash
g++ Diagnostico.cpp -o Diagnostico
```

2. Execute o programa:

```bash
./Diagnostico
```
<br>

## 🛠️ Tecnologias utilizadas

Linguagem: C++
Biblioteca padrão: iostream, string, vector, map, algorithm, cctype.

<br>

## 📁 Estrutura do projeto
Diagnostico.cpp: arquivo principal com toda a lógica do sistema.
Diagnostico.exe: versão executável do sistema (Windows).

<br>

## OBSERVAÇÕES!
O diagnóstico fornecido é apenas indicativo. Recomenda-se sempre procurar um médico para confirmação e realização de exames laboratoriais.
O sistema considera apenas os sintomas descritos pelo usuário no momento e não acessa nenhum banco de dados externo.

<br>
