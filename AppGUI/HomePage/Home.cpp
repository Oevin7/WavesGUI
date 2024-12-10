//
// Created by kevin on 12/5/24.
//

#include "Home.h"

Home::Home(QWidget *parent) : QWidget(parent) {
    layout = new QVBoxLayout(this);
}

void Home::addElement(SongGUI *song) {
    layout->addWidget(song);
}
