//Robotkol Desktop Application
#ifndef RK_MAIN_WINDOW_H
#define RK_MAIN_WINDOW_H

#include <gtkmm.h>
#include <array>
#include "axis.h"

namespace rk
{
class main_window : public Gtk::Window
{
 public:
  main_window(BaseObjectType* cobject
	      ,const Glib::RefPtr<Gtk::Builder>& refBuilder);
  ~main_window();
  
  static main_window* create();

 protected:
  Glib::RefPtr<Gtk::Builder> _refBuilder;
  
private:
  void on_axis_1_changed();
  void on_axis_2_changed();
  void on_axis_3_changed();
  void on_axis_4_changed();
  
  std::array<Gtk::Scale*, 4> _scales;
  axis_handler _axis_handler;
};
}

#endif
