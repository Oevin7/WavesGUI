//
// Created by kevin on 12/5/24.
//

#ifndef SIDEBARBUTTONS_H
#define SIDEBARBUTTONS_H

#include <QPushButton>

class SidebarButtons : public QPushButton {
    Q_OBJECT
public:
    SidebarButtons(QWidget *parent = nullptr, QIcon icon = QIcon());

    void setIcon(QIcon &icon);

    void setText(QString &text);
private:
    QIcon icon;
    QString text;
};



#endif //SIDEBARBUTTONS_H
