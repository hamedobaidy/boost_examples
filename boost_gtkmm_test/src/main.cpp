/*
 ============================================================================
 Name        : boost_gtkmm_test.cpp
 Author      : Hamed Mohammadi
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C++,
 ============================================================================
 */

#include "examplewindow.h"
#include <gtkmm/application.h>

int main(int argc, char *argv[])
{
  Glib::RefPtr<Gtk::Application> app = Gtk::Application::create(argc, argv, "org.gtkmm.example");

  ExampleWindow window;
  window.resize(1000,800);

  //Shows the window and returns when it is closed.
  return app->run(window);
}
