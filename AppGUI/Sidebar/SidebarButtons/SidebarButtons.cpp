//
// Created by kevin on 12/5/24.
//

#include "SidebarButtons.h"

#include <utility>

SidebarButtons::SidebarButtons(QWidget *parent, QIcon icon) : QPushButton(parent) {
    this->icon = std::move(icon);
    QPushButton::setIcon(this->icon);

    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
}

void SidebarButtons::setIcon(QIcon &icon) {
    this->icon = std::move(icon);
}

void SidebarButtons::setText(QString &text) {
    this->icon = icon;
}

