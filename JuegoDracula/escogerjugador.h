#ifndef ESCOGERJUGADOR_H
#define ESCOGERJUGADOR_H

#include <QDialog>
#include "campodejuego.h"

namespace Ui {
class EscogerJugador;
}

class EscogerJugador : public QDialog
{
    Q_OBJECT

public:
    explicit EscogerJugador(CampoDeJuego campo, QWidget *parent = 0);
    ~EscogerJugador();



private slots:

    void on_btnMazo_clicked();

    void on_btnJugador1_clicked();

private:
    Ui::EscogerJugador *ui;

public slots:



};

#endif // ESCOGERJUGADOR_H
