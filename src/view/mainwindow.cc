#include "mainwindow.h"

#include "creditwindow.h"
#include "graphwindow.h"
#include "ui_mainwindow.h"

using namespace baseFunc;

MainWindow::MainWindow(Controller *c) : ui(new Ui::MainWindow), controller_(c) {
  ui->setupUi(this);
  connect(ui->Buttons, &QButtonGroup::buttonClicked, this,
          &MainWindow::on_inputButtons_clicked);
  connect(ui->FunctionButtons, &QButtonGroup::buttonClicked, this,
          &MainWindow::on_inputFunctionButtons_clicked);
  ui->input_x->setValidator(new QRegularExpressionValidator(
      QRegularExpression("^[-]?[0-9]*[.,]?[0-9]+$"), this));
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_inputButtons_clicked(QAbstractButton *btn) {
  ui->input->setText(ui->input->text() + btn->text());
}

void MainWindow::on_inputFunctionButtons_clicked(QAbstractButton *btn) {
  ui->input->setText(ui->input->text() + btn->text() + QChar('('));
}

void MainWindow::on_pushButton_x_clicked() {
  QPushButton *btn = (QPushButton *)sender();
  ui->input->setText(ui->input->text() + btn->text());
  x = true;
}

void MainWindow::on_pushButton_equal_clicked() {
  try {
    std::string expression = ui->input->text().toLower().toStdString();
    double x = ui->input_x->text().toDouble();
    double result = controller_->CalculateMain(expression, x);
    QString res = QString::number(result, 'g', 15);
    if (x)
      ui->output_y->setText(res);
    else
      ui->input->setText(res);
  } catch (const std::exception &e) {
    QMessageBox::critical(this, "Warning", e.what());
  }
}

void MainWindow::on_pushButton_clear_clicked() {
  ui->input->clear();
  ui->input_x->clear();
  ui->output_y->clear();
}

void MainWindow::on_pushButton_graph_clicked() {
  std::string exp = ui->input->text().toStdString();
  GraphWindow window_graph(nullptr, controller_, &exp);
  window_graph.setModal(true);
  window_graph.exec();
}

void MainWindow::on_pushButton_credit_clicked() {
  CreditWindow window_credit(nullptr, controller_);
  window_credit.setModal(true);
  window_credit.exec();
}
