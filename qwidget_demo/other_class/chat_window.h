//
// Created by shecannotsee on 23-10-9.
//

#ifndef QWIDGET_DEMO_CHAT_WINDOW_H
#define QWIDGET_DEMO_CHAT_WINDOW_H

#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QPushButton>

namespace t3_chat_window_test {

class ChatWidget : public QWidget
{
 Q_OBJECT

 public:
  explicit ChatWidget(QWidget *parent = nullptr);

 private slots:
  void sendMessage();

 private:
  void setupUI();

  void displayMessage(const QString &message);

  QTextEdit *chatTextEdit{};
  QTextEdit *inputTextEdit{};
};

} // t3_chat_window_test

#endif //QWIDGET_DEMO_CHAT_WINDOW_H
