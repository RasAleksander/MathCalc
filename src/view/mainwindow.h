#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QAbstractButton>
#include <QMainWindow>
#include <QMessageBox>
#include <QRegularExpressionValidator>

#include "../controller/controller.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

namespace baseFunc {

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(Controller *c);
  ~MainWindow();

 private slots:
  void on_inputButtons_clicked(QAbstractButton *btn);
  void on_inputFunctionButtons_clicked(QAbstractButton *btn);
  void on_pushButton_equal_clicked();
  void on_pushButton_clear_clicked();
  void on_pushButton_graph_clicked();
  void on_pushButton_x_clicked();
  void on_pushButton_credit_clicked();

 private:
  Ui::MainWindow *ui;
  Controller *controller_;
  bool x = false;
};

}  // namespace baseFunc
#endif  // MAINWINDOW_H
