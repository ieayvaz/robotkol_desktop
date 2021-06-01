//Robotkol Desktop Application
#ifndef RK_APPLICATION_H
#define RK_APPLICATION_H

#include <iostream>
#include <gtkmm.h>

#include "main_window.h"

namespace rk
{
  
class rk_application : public Gtk::Application
{
 protected:
  rk_application();
  
 public:
  static Glib::RefPtr<rk_application> create();

 protected:
  void on_activate() override;

 private:
  main_window* create_window();
  void on_hide_window(Gtk::Window* window);
};
}
#endif
