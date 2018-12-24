#ifndef PACIENTE_H
#define PACIENTE_H

#include <QObject>

class Paciente
{

private:
    QString nome;
    int idade;
    QString cpf;
    QString gravidade;
    int cont=0;

public:
    explicit Paciente();
    Paciente(QString n, int m,QString x,QString y);

    QString getNome() const;
    void setNome(const QString &guarda);

    int getIdade() const;
    void setIdade(int guarda);

    QString getCpf() const;
    void setCpf(const QString guarda);

    QString getGrav() const;
    void setGrav(const QString guarda);

    int getAloc() ;


signals:

public slots:
};

#endif
