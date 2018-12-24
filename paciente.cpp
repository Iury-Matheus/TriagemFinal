#include "paciente.h"

QString Paciente::getNome() const
{
    return nome;
}

void Paciente::setNome(const QString &guarda)
{
    nome = guarda;
}

int Paciente::getIdade() const
{
    return idade;
}

void Paciente::setIdade(int guarda)
{
    idade = guarda;
}

QString Paciente::getCpf() const
{
    return cpf;
}

void Paciente::setCpf(const QString guarda)
{
    cpf = guarda;
}

QString Paciente::getGrav() const
{
    return gravidade;
}

void Paciente::setGrav(const QString guarda)
{

    gravidade = guarda;
}

int Paciente::getAloc()
{
    if(gravidade == "NORMAL"){
        cont =3;
    }
    if((gravidade == "PREFERENCIAL") || (gravidade == "PREFERÊNCIAL")){
        cont =2;
    }
    if(gravidade == "GRAVE"){
        cont =1;
    }
    return cont;
}

Paciente::Paciente()
{

}

Paciente::Paciente(QString n, int m, QString x, QString y)
{
    nome = n;
    idade = m;
    cpf = x;
    gravidade = y;
}
