#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QVector>
#include <QFileDialog>
#include <QMessageBox>

#include "gerenciadordearquivos.h"
#include "paciente.h"
#include "dados.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    Dados upa;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void atualizarEstatisticas();

private slots:
    void on_btn_insert_clicked();

    void on_btn_NameSort_clicked();

    void on_btn_GradeSort_clicked();

    void salvar();
    void carregar();

    void on_comboBox_activated(const QString &arg1);

    void on_btn_GravSort_clicked();

private:
    Ui::MainWindow *ui;
    void inserirPacienteNaTabela(Paciente paciente, int row);


};

#endif // MAINWINDOW_H
