//
// Created by shecannotsee on 23-10-8.
//

#include "windows_control.h"

namespace t4_more_qml_windows_switch_test {

void windows_control::toggleVisibility(bool isVisible) {
  // 在这里根据需要修改visible属性的值
  // 在这个示例中，我们直接将其设置为isVisible参数的值
  visible = isVisible;
}

void windows_control::setVisible(bool isVisible) {
  if (visible != isVisible)
  {
    visible = isVisible;
    emit visibilityChanged(visible);
  }
}

bool windows_control::isVisible() const {
  return visible;
}


} // t4_more_qml_windows_switch_test