/*
 * examplewindow.h
 *
 *  Created on: Jan 17, 2014
 *      Author: hamed
 */

#ifndef EXAMPLEWINDOW_H_
#define EXAMPLEWINDOW_H_

#include <gtkmm/window.h>
#include <gtkmm/checkbutton.h>
#include <gtkmm/scrolledwindow.h>
#include <gtkmm/textview.h>
#include <gtkmm/textbuffer.h>
#include <gtkmm/box.h>

class ExampleWindow: public Gtk::Window {
public:
	ExampleWindow();
	virtual ~ExampleWindow();

protected:

	void fill_buffers();

	Gtk::Box m_VBox;
	Gtk::ScrolledWindow m_ScrolledWindow;
	Gtk::TextView m_TextView;

	Glib::RefPtr<Gtk::TextBuffer> m_refTextBuffer;
};

#endif /* EXAMPLEWINDOW_H_ */
