#include "dados.h"

Dados::Dados(QObject *parent) : QObject(parent)
{

}

void Dados::inserirPaciente(const Paciente a)
{
    dados.push_back(a);
}

int Dados::Totalpaciente()
{
    return dados.size();
}

int Dados::mediaIdade()
{
    return std::accumulate(dados.begin(),dados.end(),0.0, [](int acc, Paciente a){return acc+=a.getIdade();})/dados.size();
}

void Dados::ordenarPorGravidade()
{

    std::sort(dados.begin(), dados.end(), [](Paciente a, Paciente b){return a.getAloc()<b.getAloc();});
}

void Dados::ordenarPorIdade()
{
    ordenarPorGravidade();
    std::stable_sort(dados.begin(),dados.end(),[](Paciente a, Paciente b){return a.getIdade()<b.getIdade();});
}

int Dados::size()
{
    return dados.size();
}

void Dados::clear()
{
    dados.clear();
}

Paciente Dados::operator[](int i)
{
    return dados[i];
}
