//
// Created by shecannotsee on 23-10-9.
//

#include "chat_window.h"

namespace t3_chat_window_test {


ChatWidget::ChatWidget(QWidget *parent) : QWidget(parent) {
  setupUI();
}

void ChatWidget::sendMessage() {
  QString message = inputTextEdit->toPlainText();
  if (!message.isEmpty()) {
    // 在消息框中显示自己发送的消息
    displayMessage("You: " + message);

    // 在实际应用中，这里应该将消息发送给其他人或服务器
    // 在这个示例中，只是清空输入框以模拟发送消息
    inputTextEdit->clear();
  }
}

void ChatWidget::setupUI() {
  QVBoxLayout *layout = new QVBoxLayout(this);

  chatTextEdit = new QTextEdit(this);
  chatTextEdit->setReadOnly(true);
  layout->addWidget(chatTextEdit);

  inputTextEdit = new QTextEdit(this);
  layout->addWidget(inputTextEdit);

  QPushButton *sendButton = new QPushButton("发送", this);
  layout->addWidget(sendButton);

  connect(sendButton, &QPushButton::clicked, this, &ChatWidget::sendMessage);

  setLayout(layout);

}

void ChatWidget::displayMessage(const QString &message) {
  chatTextEdit->append(message);
}


} // t3_chat_window_test