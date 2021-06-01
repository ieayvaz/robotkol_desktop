//Robotkol Desktop Application

#include "rk_application.h"

namespace rk
{
  
rk_application::rk_application()
  : Gtk::Application("org.ie.robotkol") {}

Glib::RefPtr<rk_application> rk_application::create()
{
  return Glib::RefPtr<rk_application>(new rk_application());
}

main_window* rk_application::create_window()
{
  auto window = main_window::create();
  add_window(*window);
  
  window->signal_hide().connect(sigc::bind<Gtk::Window*>
				(sigc::mem_fun(*this, &rk_application::on_hide_window),
				 window));
  
  return window;
}

void rk_application::on_activate()
{
  auto window = create_window();
  window->present(); 
}

void rk_application::on_hide_window(Gtk::Window* window)
{
  delete window;
}
}
