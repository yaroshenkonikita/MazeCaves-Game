#include "options_t.h"

using namespace s21;

Options_t::Options_t() { LoadSettings(); }

void Options_t::LoadSettings() {
  background_color[0] = settings.value("background_color_red", 0.0).toFloat();
  background_color[1] = settings.value("background_color_green", 0.0).toFloat();
  background_color[2] = settings.value("background_color_blue", 0.0).toFloat();
  background_color[3] = settings.value("background_color_alpha", 1.0).toFloat();
  edge_color[0] = settings.value("edge_color_red", 1.0).toFloat();
  edge_color[1] = settings.value("edge_color_green", 1.0).toFloat();
  edge_color[2] = settings.value("edge_color_blue", 1.0).toFloat();
  edge_color[3] = settings.value("edge_color_alpha", 1.0).toFloat();
  edge_width = settings.value("edge_width", 2).toInt();
}

void Options_t::SaveSettings() {
  settings.setValue("edge_color_red", edge_color[0]);
  settings.setValue("edge_color_green", edge_color[1]);
  settings.setValue("edge_color_blue", edge_color[2]);
  settings.setValue("edge_color_alpha", edge_color[3]);
  settings.setValue("background_color_red", background_color[0]);
  settings.setValue("background_color_green", background_color[1]);
  settings.setValue("background_color_blue", background_color[2]);
  settings.setValue("background_color_alpha", background_color[3]);
  settings.setValue("edge_width", edge_width);
}
