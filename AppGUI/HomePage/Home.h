//
// Created by kevin on 12/5/24.
//

#ifndef HOME_H
#define HOME_H
#include <qboxlayout.h>
#include <qwidget.h>

#include "SongGUI.h"


class Home : public QWidget {
    Q_OBJECT
public:
    explicit Home(QWidget *parent = nullptr);

    void addElement(SongGUI* song);

private:
    QVBoxLayout *layout;
};



#endif //HOME_H
