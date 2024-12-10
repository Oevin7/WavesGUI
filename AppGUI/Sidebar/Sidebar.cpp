//
// Created by kevin on 12/5/24.
//

#include <iostream>
#include "Sidebar.h"

#include "../HomePage/Home.h"
#include "SidebarButtons/SidebarButtons.h"

Sidebar::Sidebar(QWidget *parent) : QWidget(parent) {
    layout = new QVBoxLayout(this);

    layout->setSpacing(8);
    layout->setContentsMargins(4, 4, 4, 4);
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    logo = new QLabel(this);
    QPixmap logoPixmap("/home/kevin/CLionProjects/Waves/AppGUI/icons/Waves.png");
    logo->setPixmap(logoPixmap.scaled(200, 200, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    logo->setAlignment(Qt::AlignCenter);

    layout->addWidget(logo);
    SidebarButtons *home = new SidebarButtons(this, QIcon("/home/kevin/CLionProjects/Waves/AppGUI/icons/icons8-home-pulsar-line/icons8-home-96.png"));

    layout->addWidget(home);

    SidebarButtons *library = new SidebarButtons(this, QIcon("/home/kevin/CLionProjects/Waves/AppGUI/icons/icons8-musical-note-pulsar-line/icons8-musical-note-96.png"));
    layout->addWidget(library);

    layout->addStretch(2);
    this->setFixedWidth(250);
}
