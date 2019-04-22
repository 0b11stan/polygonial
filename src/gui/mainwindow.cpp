#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      factsEngine("/tmp/polygonial"),
      inferenceEngine(factsEngine, rulesEngine),
      ui(new Ui::MainWindow) {
  ui->setupUi(this);

  for (int x = 3; x <= 10; x++)
    ui->cb_sides->addItem(QString(std::to_string(x).c_str()));
  this->on_cb_sides_activated(0);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_pushButton_clicked() {
  int chosen_sides = ui->cb_sides->currentText().toInt();
  int chosen_right_angles = ui->cb_right_angles->currentText().toInt();
  int chosen_parallel_sides = ui->cb_parallel_sides->currentText().toInt();
  int chosen_same_length_sides =
      ui->cb_same_length_sides->currentText().toInt();
  std::cout << "sides : " << chosen_sides << std::endl;
  std::cout << "right angles : " << chosen_sides << std::endl;
  std::cout << "parallel sides : " << chosen_parallel_sides << std::endl;
  std::cout << "same length sides : " << chosen_same_length_sides << std::endl;

  Record record(chosen_sides, chosen_right_angles, chosen_parallel_sides,
                chosen_same_length_sides);
  inferenceEngine.process(record);
  std::cout << record.get_label() << std::endl;
  ui->result_label->setText(record.to_string().c_str());
}

void MainWindow::on_cb_sides_activated(int index) {
  int chosen_sides = index + 3;

  // TODO : nombres d'angles droit avec formule
  for (int x = 0; x <= chosen_sides; x++)
    ui->cb_right_angles->addItem(QString(std::to_string(x).c_str()));

  for (int x = 0; x <= chosen_sides; x++)
    ui->cb_parallel_sides->addItem(QString(std::to_string(x).c_str()));

  for (int x = 0; x <= chosen_sides; x++)
    ui->cb_same_length_sides->addItem(QString(std::to_string(x).c_str()));
}
