//Robotkol Desktop Application
#ifndef RK_MAIN_WINDOW_H
#define RK_MAIN_WINDOW_H

#include <gtkmm.h>

class main_window : public Gtk::Window
{
 public:
  main_window(BaseObjectType* cobject
	      ,const Glib::RefPtr<Gtk::Builder>& refBuilder);

  static main_window* create();

 protected:
  Glib::RefPtr<Gtk::Builder> _refBuilder;
  
};

#endif
