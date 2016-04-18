#ifndef GANADOR_H
#define GANADOR_H

#include <string>
#include <QDialog>

namespace Ui {
class Ganador;
}

class Ganador : public QDialog
{
    Q_OBJECT

public:
    explicit Ganador(QString ganadorJugador, QWidget *parent = 0);
    ~Ganador();

private:
    Ui::Ganador *ui;
};

#endif // GANADOR_H
