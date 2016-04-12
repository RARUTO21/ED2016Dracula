#ifndef ESCOGERJUGADOR_H
#define ESCOGERJUGADOR_H

#include <QDialog>

namespace Ui {
class EscogerJugador;
}

class EscogerJugador : public QDialog
{
    Q_OBJECT

public:
    explicit EscogerJugador(QWidget *parent = 0);
    ~EscogerJugador();

private:
    Ui::EscogerJugador *ui;
};

#endif // ESCOGERJUGADOR_H
