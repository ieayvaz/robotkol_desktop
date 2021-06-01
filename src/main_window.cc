//Robotkol Desktop Application

#include "main_window.h"
#include <stdexcept>

namespace rk
{
main_window::main_window(BaseObjectType* cobject,
			 const Glib::RefPtr<Gtk::Builder>& refBuilder)
  : _refBuilder(refBuilder),
    Gtk::Window(cobject)
{
  for(auto& ref_scale : _scales)
    {
      ref_scale = nullptr;
    }
  
  _refBuilder->get_widget("eksen_1_scale", _scales[0]);
  _refBuilder->get_widget("eksen_2_scale", _scales[1]);
  _refBuilder->get_widget("eksen_3_scale", _scales[2]);
  _refBuilder->get_widget("eksen_4_scale", _scales[3]);

  _scales[0]->signal_value_changed().connect
    (sigc::mem_fun(*this, &main_window::on_axis_1_changed));

  _scales[1]->signal_value_changed().connect
    (sigc::mem_fun(*this, &main_window::on_axis_2_changed));

  _scales[2]->signal_value_changed().connect
    (sigc::mem_fun(*this, &main_window::on_axis_3_changed));

  _scales[3]->signal_value_changed().connect
    (sigc::mem_fun(*this, &main_window::on_axis_4_changed));

  _axis_handler.set_active();
}

main_window::~main_window()
{
  _axis_handler.set_deactive();
}
  
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

void main_window::on_axis_1_changed()
{
  _axis_handler.set_axis_angle(axis_type::axis_1, _scales[0]->get_value());
}

void main_window::on_axis_2_changed()
{
  _axis_handler.set_axis_angle(axis_type::axis_2, _scales[1]->get_value());
}

void main_window::on_axis_3_changed()
{
  _axis_handler.set_axis_angle(axis_type::axis_3, _scales[2]->get_value());
}

void main_window::on_axis_4_changed()
{
  _axis_handler.set_axis_angle(axis_type::axis_4, _scales[3]->get_value());
}
  
}

