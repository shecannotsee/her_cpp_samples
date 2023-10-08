//
// Created by shecannotsee on 23-10-8.
//

#ifndef QML_DEMO_WINDOWS_CONTROL_H
#define QML_DEMO_WINDOWS_CONTROL_H

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QObject>

namespace t4_more_qml_windows_switch_test {

class windows_control : public QObject {
 Q_OBJECT
 public:
  bool visible = false;
  Q_INVOKABLE void toggleVisibility(bool isVisible);

 signals:
  void visibilityChanged(bool isVisible);

 private:
  Q_PROPERTY(bool visible READ isVisible WRITE setVisible NOTIFY visibilityChanged);

  void setVisible(bool isVisible);

  bool isVisible() const;
};


} // t4_more_qml_windows_switch_test

#endif //QML_DEMO_WINDOWS_CONTROL_H
