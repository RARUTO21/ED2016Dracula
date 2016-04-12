#ifndef ESCOGERDIRECCION_H
#define ESCOGERDIRECCION_H

#include <QDialog>

namespace Ui {
class EscogerDireccion;
}

class EscogerDireccion : public QDialog
{
    Q_OBJECT

public:
    explicit EscogerDireccion(QWidget *parent = 0);
    ~EscogerDireccion();

private:
    Ui::EscogerDireccion *ui;
};

#endif // ESCOGERDIRECCION_H
