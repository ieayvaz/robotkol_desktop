//Robotkol Desktop Application

#include "main_window.h"
#include <stdexcept>

main_window::main_window(BaseObjectType* cobject,
			 const Glib::RefPtr<Gtk::Builder>& refBuilder)
  : _refBuilder(refBuilder),
    Gtk::Window(cobject) {}

main_window* main_window::create()
{
  std::string file_path = "res/main_window.glade";
  auto builder = Gtk::Builder::create_from_file(file_path);

  main_window* window= nullptr;
  try
    {
      builder->get_widget_derived("main_window", window);
    }
  catch(const Glib::FileError& ex)
    {
      throw std::runtime_error("Dosya hatası : " + file_path +
			       "\n" + ex.what() + "\n");
    }
  catch(const Glib::MarkupError& ex)
    {
      throw std::runtime_error("Glade yazım hatası : " + file_path +
			       "\n" + ex.what() + "\n");
    }
  catch(const Gtk::BuilderError& ex)
    {
      throw std::runtime_error("Glade builder hatası : " + file_path +
			       "\n" + ex.what() + "\n");
    }
  return window;
}


