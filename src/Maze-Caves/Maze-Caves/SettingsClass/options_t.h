#ifndef CPP4_3DVIEWER_V2_0_1_OPTIONS_T_H_
#define CPP4_3DVIEWER_V2_0_1_OPTIONS_T_H_

#include <QSettings>

namespace s21 {
/**
 * @brief Класс для отслеживания и обновления настроек через QSettings
 */
struct Options_t {
  Options_t();  ///<Дефолтный конструктор

  QSettings settings{"YoungMales",
                     "Maze"};  ///< Экземпляр класса QSettings для
                               ///< сохранения и загрузки настроек

  int edge_width{};        ///< Толщина ребра
  float background_color[4]{},  ///< Цвет фона {red, green, blue}
      edge_color[4]{};          ///< Цвет ребра {red, green, blue}

  void SaveSettings();  ///< Функция сохранения текущих значений в реестр

  void
  LoadSettings();  ///< Функция загрузки данных из реестра в текущие значения
};

}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_0_1_OPTIONS_T_H_
