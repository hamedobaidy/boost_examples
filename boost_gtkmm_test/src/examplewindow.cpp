/*
 * examplewindow.cpp
 *
 *  Created on: Jan 17, 2014
 *      Author: hamed
 */

#include "examplewindow.h"
#include "boostmultiprecisiontest.h"
#include <iostream>

ExampleWindow::ExampleWindow()
: m_VBox(Gtk::ORIENTATION_VERTICAL)
{
  set_title("Tesing boost multiprecision");
  set_border_width(10);

  add(m_VBox);

  //Add the TreeView, inside a ScrolledWindow, with the button underneath:
    m_ScrolledWindow.add(m_TextView);

    //Only show the scrollbars when they are necessary:
    m_ScrolledWindow.set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);

    m_VBox.pack_start(m_ScrolledWindow);

    fill_buffers();

  show_all_children();
}

ExampleWindow::~ExampleWindow()
{
}

void ExampleWindow::fill_buffers()
{
  m_refTextBuffer = Gtk::TextBuffer::create();
  boost_multiprecision_test test;
  string text = test.test_precision();
  m_refTextBuffer->set_text(text);
  m_TextView.set_buffer(m_refTextBuffer);
}


