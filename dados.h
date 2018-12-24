#ifndef DADOS_H
#define DADOS_H

#include <QObject>
#include <QVector>
#include <numeric>
#include <algorithm>

#include "paciente.h"

class Dados : public QObject
{
    Q_OBJECT
private:
    QVector<Paciente> dados;

public:
    explicit Dados(QObject *parent = nullptr);
    void inserirPaciente(const Paciente a);
    int Totalpaciente();
    int mediaIdade();
    void ordenarPorGravidade();
    void ordenarPorIdade();

    int size();
    void clear();

    Paciente operator[](int i);


signals:

public slots:
};

#endif // Dados_H
