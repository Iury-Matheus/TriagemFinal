#include "gerenciadordearquivos.h"

GerenciadorDeArquivos::GerenciadorDeArquivos()
{

}

bool GerenciadorDeArquivos::salvarDados(QString &arquivo, Dados &dados)
{
    QFile file(arquivo);

    if(!file.open(QIODevice::WriteOnly)){
        return false;
    }

    QTextStream out(&file);

    for(int i=0;i<dados.size();i++){
        out << dados[i].getNome()<<","<<dados[i].getIdade()<<","<<dados[i].getCpf()<<","<<dados[i].getGrav()<<"\n";
    }

    file.close();
    return true;
}

bool GerenciadorDeArquivos::carregarDados(QString &arquivo, Dados &dados)
{
    QFile file(arquivo);

    if(!file.open(QIODevice::ReadOnly)){
        return false;
    }

    QTextStream in(&file);

    QString linha;

    while(!in.atEnd()){
        linha = in.readLine();

        QStringList guarda = linha.split(",");

        Paciente a(guarda[0],guarda[1].toInt(),guarda[2],guarda[3]);
                dados.inserirPaciente(a);

    }
    return true;
}
