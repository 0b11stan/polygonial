#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string>
#include "iostream"

#include <src/core/Record.hpp>
#include "ui_mainwindow.h"

#include <src/core/InferenceEngine.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  explicit MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private slots:
  void on_pushButton_clicked();

  void on_cb_sides_activated(int index);

 private:
  FactsEngine factsEngine;
  RulesEngine rulesEngine;
  InferenceEngine inferenceEngine;

  Ui::MainWindow *ui;
};

#endif  // MAINWINDOW_H
