#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->actionSalvar,SIGNAL(triggered()), this, SLOT(salvar()));
    connect(ui->actionCarregar,SIGNAL(triggered()), this, SLOT(carregar()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::atualizarEstatisticas()
{
    ui->lbl_avg->setText(QString::number(upa.Totalpaciente(),'f',2));
    ui->lbl_highest->setText(QString::number(upa.mediaIdade(),'f',2));
}

void MainWindow::inserirPacienteNaTabela(Paciente paciente, int row)
{
    ui->tbl_data->setItem(row,0,new QTableWidgetItem(paciente.getNome()));
    ui->tbl_data->setItem(row,1,new QTableWidgetItem(QString::number(paciente.getIdade())));
    ui->tbl_data->setItem(row,2,new QTableWidgetItem(paciente.getCpf()));
    ui->tbl_data->setItem(row,3,new QTableWidgetItem(paciente.getGrav()));
}

void MainWindow::salvar()
{

    QString nomeArquivo = QFileDialog::getSaveFileName(this,"Lista de Pacientes","","Texto Puro(*.txt);;Arquivos Separado por Vírgulas(*.csv)");
    if( GerenciadorDeArquivos::salvarDados(nomeArquivo,upa) ){
        QMessageBox::information(this, "Salvar Informação","Dados Salvos com Sucesso");
    }else{
        QMessageBox::information(this, "Salvar Informação","Não foi possível salvar os dados");
    }

}

void MainWindow::carregar()
{
    QString nomeArquivo = QFileDialog::getOpenFileName(this,"Lista de Pacientes","","Texto Puro(*.txt);;Arquivos Separado por Vírgulas(*.csv)");
    upa.clear();

    if(GerenciadorDeArquivos::carregarDados(nomeArquivo,upa)){

        ui->tbl_data->clearContents();
        for(int i=0;i<upa.size();i++){

            if(i >= ui->tbl_data->rowCount())
                ui->tbl_data->insertRow(i);

            inserirPacienteNaTabela(upa[i],i);
        }

    }else{
        QMessageBox::information(this, "Carregar turma","Não foi possível carregar os dados");
    }

}

void MainWindow::on_btn_insert_clicked()
{
    if(ui->le_nameInput->text().size() != 0 && ui->le_idadeInput->text().size() != 0 && ui->le_cpfInput->text().size() !=0 && ui->le_grav->text().size() != 0){
        Paciente paciente;
        paciente.setNome(ui->le_nameInput->text());
        paciente.setIdade(ui->le_idadeInput->text().toInt());
        paciente.setCpf(ui->le_cpfInput->text());
        paciente.setGrav(ui->le_grav->text().toUpper());

        int qnt_row = ui->tbl_data->rowCount();

        ui->tbl_data->insertRow(qnt_row);
        inserirPacienteNaTabela(paciente, qnt_row);

        ui->le_nameInput->clear();
        ui->le_idadeInput->clear();
        ui->le_cpfInput->clear();
        ui->le_grav->clear();

        upa.inserirPaciente(paciente);
        atualizarEstatisticas();
    }
}

void MainWindow::on_btn_GravSort_clicked()
{
    ui->tbl_data->clearContents();

    upa.ordenarPorGravidade();
    for(int i = 0; i<upa.size(); i++){
        inserirPacienteNaTabela(upa[i], i);
    }
}

void MainWindow::on_btn_GradeSort_clicked()
{
    ui->tbl_data->clearContents();
    upa.ordenarPorIdade();
    for(int i = 0; i<upa.size();i++){
        inserirPacienteNaTabela(upa[i],i);
    }
}

void MainWindow::on_comboBox_activated(const QString &arg1)
{

}


