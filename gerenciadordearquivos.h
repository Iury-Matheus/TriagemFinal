#ifndef GERENCIADORDEARQUIVOS_H
#define GERENCIADORDEARQUIVOS_H

#include <QObject>
#include <QFile>
#include <QTextStream>
#include <fstream>
#include <QDebug>

#include "dados.h"
#include "paciente.h"


class GerenciadorDeArquivos
{
public:
    GerenciadorDeArquivos();
    static bool salvarDados(QString &arquivo, Dados &dados);
    static bool carregarDados(QString &arquivo, Dados &dados);
};

#endif // GERENCIADORDEARQUIVOS_H
