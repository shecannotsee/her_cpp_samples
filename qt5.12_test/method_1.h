//
// Created by shecannotsee on 2023/2/8.
//

#ifndef QT5_12_TEST_QT5_12_TEST_METHOD_1_H_
#define QT5_12_TEST_QT5_12_TEST_METHOD_1_H_

#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>

namespace method_1 {

int main(int argc, char** argv) {
  QApplication app(argc, argv);

  QMainWindow window;
  window.setWindowTitle("My Window");
  window.resize(400, 300);

  QWidget *centralWidget = new QWidget;
  window.setCentralWidget(centralWidget);

  QPushButton *button = new QPushButton("Click Me!", centralWidget);

  window.show();

  return app.exec();

};

};// namespace method_1 {

#endif //QT5_12_TEST_QT5_12_TEST_METHOD_1_H_
