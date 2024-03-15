#include "graphwindow.h"

#include "ui_graphwindow.h"

using namespace baseFunc;

GraphWindow::GraphWindow(QWidget *parent, Controller *gc, std::string *exp)
    : QDialog(parent),
      ui(new Ui::GraphWindow),
      graph_controller_(gc),
      expression_(exp) {
  ui->setupUi(this);
  setWindowTitle("Graph");
  SetStartValues();
  PrintGraph();
}

GraphWindow::~GraphWindow() { delete ui; }

void GraphWindow::SetStartValues() {
  ui->max_x->setValue(10);
  ui->min_x->setValue(-10);
  ui->max_y->setValue(10);
  ui->min_y->setValue(-10);
}

void GraphWindow::PrintGraph() {
  try {
    Calculator::CoordinatesXY &coordinates = graph_controller_->CalculateGraph(
        *expression_, 10000, GetMinX(), GetMaxX(), GetMinY(), GetMaxY());
    QVector<double> x(coordinates.first.begin(), coordinates.first.end());
    QVector<double> y(coordinates.second.begin(), coordinates.second.end());
    ui->widget->addGraph();
    ui->widget->graph(0)->setData(x, y);
    ui->widget->xAxis->setRange(GetMinX(), GetMaxX());
    ui->widget->yAxis->setRange(GetMinY(), GetMaxY());
    ui->widget->replot();
  } catch (const std::exception &e) {
    QMessageBox::critical(this, "Warning", e.what());
  }
}

void GraphWindow::on_replot_clicked() { PrintGraph(); }

double GraphWindow::GetMinX() { return ui->min_x->value(); }

double GraphWindow::GetMaxX() { return ui->max_x->value(); }

double GraphWindow::GetMinY() { return ui->min_y->value(); }

double GraphWindow::GetMaxY() { return ui->max_y->value(); }
